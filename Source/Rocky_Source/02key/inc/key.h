#ifndef KEY_H
#define KEY_H

#define  pEXECPTION_IRQ (*(volatile unsigned int *)(0xD0037400 + 0x18))

#define  EXT_INT_2_CON (*(volatile unsigned int *)(0xE0200E08)) // 描述到底以什么样方式来触发, 功能选择
#define  EXT_INT_2_MASK (*(volatile unsigned int *)(0xE0200F08)) // 开关, 型号是否能往后传, 要打开
#define  EXT_INT_2_PEND (*(volatile unsigned int *)(0xE0200F48)) // 记录员, 处理之后, 标记已经处理完了.

#define  VIC0INTENABLE (*(volatile unsigned int *)(0xF2000010))
#define  VIC0ADDRESS (*(volatile unsigned int *)(0xF2000F00))
#define  VIC0VECTADDR16 (*(volatile unsigned int *)(0xF2000140))

void key_init(void);

void key1_handler(void);

void irq_c_handler(void);

void irq_init(void);

#endif