#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H

struct s5pc1xx_gpio_bank {
    unsigned int    con;
    unsigned int    dat;
    unsigned int    pull;
    unsigned int    drv;
    unsigned int    pdn_con;
    unsigned int    pdn_pull;
    unsigned char   res1[8];
};

struct s5pv210_gpio {
    struct s5pc1xx_gpio_bank gpio_a0;
    struct s5pc1xx_gpio_bank gpio_a1;
    struct s5pc1xx_gpio_bank gpio_b;
    struct s5pc1xx_gpio_bank gpio_c0;
    struct s5pc1xx_gpio_bank gpio_c1;
    struct s5pc1xx_gpio_bank gpio_d0;
    struct s5pc1xx_gpio_bank gpio_d1;
    struct s5pc1xx_gpio_bank gpio_e0;
    struct s5pc1xx_gpio_bank gpio_e1;
    struct s5pc1xx_gpio_bank gpio_f0;
    struct s5pc1xx_gpio_bank gpio_f1;
    struct s5pc1xx_gpio_bank gpio_f2;
    struct s5pc1xx_gpio_bank gpio_f3;
    struct s5pc1xx_gpio_bank gpio_g0;
    struct s5pc1xx_gpio_bank gpio_g1;
    struct s5pc1xx_gpio_bank gpio_g2;
    struct s5pc1xx_gpio_bank gpio_g3;
    struct s5pc1xx_gpio_bank gpio_i;
    struct s5pc1xx_gpio_bank gpio_j0;
    struct s5pc1xx_gpio_bank gpio_j1;
    struct s5pc1xx_gpio_bank gpio_j2;
    struct s5pc1xx_gpio_bank gpio_j3;
    struct s5pc1xx_gpio_bank gpio_j4;
};

#define S5PV210_GPIO_BASE (0xE0200000)

#endif

