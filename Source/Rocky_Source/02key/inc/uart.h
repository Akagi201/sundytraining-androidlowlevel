#ifndef UART_H
#define UART_H

struct s5pv2xx_uart {
    unsigned int    ulcon;
    unsigned int    ucon;
    unsigned int    ufcon;
    unsigned int    umcon;
    unsigned int    utrstat;
    unsigned int    uerstat;
    unsigned int    ufstat;
    unsigned int    umstat;
    unsigned char   utxh;
    unsigned char   res1[3];
    unsigned char   urxh;
    unsigned char   res2[3];
    unsigned int    ubrdiv;
    unsigned short  udivslot;
    unsigned char   res3[2];
    unsigned char   res4[0x3d0];
};

#define S5PV210_UART_BASE (0xE2900000)

void uart_init(void);

void myputc(char c);

void myputs(const char *str);

#endif
