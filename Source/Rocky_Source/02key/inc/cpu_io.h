#ifndef _S5PV210_CPU_H
#define _S5PV210_CPU_H

#define	__REG(x)		(*(volatile unsigned int *)(x))

#define readb(a)		(*(volatile unsigned char *)(a))
#define readw(a)		(*(volatile unsigned short *)(a))
#define readl(a)		(*(volatile unsigned int *)(a))

#define writeb(v,a)		(*(volatile unsigned char *)(a) = (v))
#define writew(v,a)		(*(volatile unsigned short *)(a) = (v))
#define writel(v,a)		(*(volatile unsigned int *)(a) = (v))

#endif
