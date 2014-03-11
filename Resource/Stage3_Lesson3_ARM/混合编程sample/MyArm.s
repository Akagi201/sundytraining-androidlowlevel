	AREA myARM,CODE,READONLY
	EXPORT my_strcpy	
	IMPORT cFun
	ENTRY

start 
	MOV R0,#1
	MOV R1,#2
	MOV R2,#3
	BL cFun	
	MOV R4,R0

my_strcpy
loop
	LDRB R4,[R0],#1
	CMP R4,#0
	BEQ over
	STRB R4,[R1],#1
	B loop
over 
	END