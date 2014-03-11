;********************************************************************************
; Institute of Automation,Chinese Academy of Sciences
;Description: This example shows the UART communication！
;Author: JuGuang,Lee
;Date:
;********************************************************************************
	UARTLCON0 EQU 0x3FFD000
	UARTCONT0 EQU 0x3FFD004
	UARTSTAT0 EQU 0x3FFD008
	UTXBUF0 EQU 0x3FFD00C
	UARTBRD0 EQU 0x3FFD014
AREA Init,CODE,READONLY
ENTRY

;**************************************************
;LED Display
;**************************************************

	LDR R1,=0x3FF5000
	LDR R0,=&ff
	STR R0,[R1]
	LDR R1,=0x3FF5008
	LDR R0,=&ff
	STR R0,[R1]

;*************************************************
;UART0 line control register
;*************************************************
	LDR R1,=UARTLCON0
	LDR R0,=0x03
	STR R0,[R1]
;**************************************************
;UART0 control regiser
;**************************************************
	LDR R1,=UARTCONT0
	LDR R0,=0x9
	STR R0,[R1]
;**************************************************
;UART0 baud rate divisor regiser
;Baudrate=19200，对应于50MHz的系统工作频率
;***************************************************
	LDR R1,=UARTBRD0
	LDR R0,=0x500
	STR R0,[R1]
;***************************************************
;Print the messages!
;***************************************************
LOOP
	LDR R0,=Line1
	BL PrintLine
	LDR R0,=Line2
	BL PrintLine
	LDR R0,=Line3
	BL PrintLine
	LDR R0,=Line4
	BL PrintLine
	LDR R1,=0x7FFFFF
LOOP1
	SUBS R1,R1,#1
	BNE LOOP1
	B LOOP
;***************************************************
;Print line
;***************************************************
PrintLine
	MOV R4,LR
	MOV R5,R0
Line
	LDRB R1,[R5],#1
	AND R0,R1,#&FF
	TST R0,#&FF
	MOVEQ PC,R4
	BL PutByte
	B Line
PutByte
	LDR R3,=UARTSTAT0
	LDR R2,[R3]
	TST R2,#&40
	BEQ PutByte
	LDR R3,=UTXBUF0
	STR R0,[R3]
	MOV PC,LR
	Line1 DCB &A,&D,"******************************************************************",0
	Line2 DCB &A,&D,"Chinese Academy of Sciences,Institute of Automation,Complex System Lab.",0
	Line3 DCB &A,&D," ARM Development Board Based on Samsung ARM S3C4510B.",0
	Line4 DCB &A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,&A,&D,0

END