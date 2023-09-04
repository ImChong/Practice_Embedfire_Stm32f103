/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:29:59
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 23:15:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : STM32F103 指南者按键检测
 * https://www.bilibili.com/video/BV1Xs411g7Aj/?p=19&spm_id_from=pageDriver&vd_source=75275452d1d334b4d80721d4823e4631
 * https://www.bilibili.com/video/BV1Xs411g7Aj/?p=20&spm_id_from=pageDriver&vd_source=75275452d1d334b4d80721d4823e4631
 */
#include "bsp_led.h"	/* 此头文件将添加 stm32f10x.h */
#include "bsp_key.h"	/* 此头文件将添加 stm32f10x.h */

#define BIT_BAND_OPERATION_OUTPUT_EN 1     /* 是否开启位带操作相关代码 */
#define BIT_BAND_OPERATION_INTPUT_EN 0     /* 是否开启位带操作相关代码 */

/* GPIOB 输出 */
#define GPIOB_ODR_ADDR          (GPIOB_BASE + 0x0C)
#define PB_OUT(bitNum)          *(unsigned int *)((GPIOB_ODR_ADDR & 0xF0000000)+0x02000000+((GPIOB_ODR_ADDR & 0x00FFFFFF)<<5)+(bitNum<<2))
/* GPIOA 输入 */
#define GPIOA_IDR_ADDR          (GPIOA_BASE + 0x08)
#define PA_IN(bitNum)           *(unsigned int *)((GPIOA_IDR_ADDR & 0xF0000000)+0x02000000+((GPIOA_IDR_ADDR & 0x00FFFFFF)<<5)+(bitNum<<2))
/* GPIOC 输入 */
#define GPIOC_IDR_ADDR          (GPIOC_BASE + 0x08)
#define PC_IN(bitNum)           *(unsigned int *)((GPIOC_IDR_ADDR & 0xF0000000)+0x02000000+((GPIOC_IDR_ADDR & 0x00FFFFFF)<<5)+(bitNum<<2))

/* ==================================================================================================== */
/* ==================================================================================================== */
/* 把 “位带地址 + 位序号” 转换成别名地址的宏 */
#define BITBAND(addr, bitNum)   ((addr & 0xF0000000)+0x02000000+((addr & 0x00FFFFFF)<<5)+(bitNum<<2))
/* 把一个地址转换成一个指针 */
#define MEM_ADDR(addr)          *((volatile unsigned long *)(addr))
/* 把位带别名区地址转换成指针 */
#define BIT_ADDR(addr, bitNum)  MEM_ADDR(BITBAND(addr, bitNum))

/* GPIO ODR 和 IDR 寄存器地址映射 */
#define GPIOA_ODR_Addr (GPIOA_BASE + 0x0C) //0x4001080C
#define GPIOB_ODR_Addr (GPIOB_BASE + 0x0C) //0x40010C0C
#define GPIOC_ODR_Addr (GPIOC_BASE + 0x0C) //0x4001100C
#define GPIOD_ODR_Addr (GPIOD_BASE + 0x0C) //0x4001140C
#define GPIOE_ODR_Addr (GPIOE_BASE + 0x0C) //0x4001180C
#define GPIOF_ODR_Addr (GPIOF_BASE + 0x0C) //0x40011A0C
#define GPIOG_ODR_Addr (GPIOG_BASE + 0x0C) //0x40011E0C

#define GPIOA_IDR_Addr (GPIOA_BASE + 0x0C) //0x40010808
#define GPIOB_IDR_Addr (GPIOB_BASE + 0x0C) //0x40010C08
#define GPIOC_IDR_Addr (GPIOC_BASE + 0x0C) //0x40011008
#define GPIOD_IDR_Addr (GPIOD_BASE + 0x0C) //0x40011408
#define GPIOE_IDR_Addr (GPIOE_BASE + 0x0C) //0x40011808
#define GPIOF_IDR_Addr (GPIOF_BASE + 0x0C) //0x40011A08
#define GPIOG_IDR_Addr (GPIOG_BASE + 0x0C) //0x40011E08

/* 单独操作 GPIO 的某一个 IO 口，n(0,1,2...16),n 表示具体是哪一个 IO 口 */
#define PAout(n)    BIT_ADDR(GPIOA_ODR_Addr,n) //输出
#define PAin(n)     BIT_ADDR(GPIOA_IDR_Addr,n) //输入

#define PBout(n)    BIT_ADDR(GPIOB_ODR_Addr,n) //输出
#define PBin(n)     BIT_ADDR(GPIOB_IDR_Addr,n) //输入

#define PCout(n)    BIT_ADDR(GPIOC_ODR_Addr,n) //输出
#define PCin(n)     BIT_ADDR(GPIOC_IDR_Addr,n) //输入

#define PDout(n)    BIT_ADDR(GPIOD_ODR_Addr,n) //输出
#define PDin(n)     BIT_ADDR(GPIOD_IDR_Addr,n) //输入

#define PEout(n)    BIT_ADDR(GPIOE_ODR_Addr,n) //输出
#define PEin(n)     BIT_ADDR(GPIOE_IDR_Addr,n) //输入

#define PFout(n)    BIT_ADDR(GPIOF_ODR_Addr,n) //输出
#define PFin(n)     BIT_ADDR(GPIOF_IDR_Addr,n) //输入

#define PGout(n)    BIT_ADDR(GPIOG_ODR_Addr,n) //输出
#define PGin(n)     BIT_ADDR(GPIOG_IDR_Addr,n) //输入
/* ==================================================================================================== */
/* ==================================================================================================== */

/**
 * @description: 延迟函数
 * =================================================================================
 * @param {__IO uint32_t} nCount
 * @return {*}
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/**
 * @description: 主函数
 * 程序来到 main 函数之前，启动文件：startup_stm32f10x_hd.s 已经调用
 * SystemInit() 函数把系统时钟初始化成 72MHZ
 * SystemInit() 在 system_stm32f10x.c 中定义
 * 如果用户想修改系统时钟，可自行编写程序修改
 * =================================================================================
 * @return {*}
 */
int main(void)
{
    /* 来到这里的时候，系统的时钟已经被配置成72M */

    LED_GPIO_Config();		/* LED GPIO初始化：默认输出拉低，此时所有初始化的 LED 灯都会被点亮 */
    KEY_GPIO_Config(KEY1_GPIO_CLK, KEY1_GPIO, KEY1_PIN_MSK);                    /* 按键1 初始化 */
    KEY_GPIO_Config(KEY2_GPIO_CLK, KEY2_GPIO, KEY2_PIN_MSK);                    /* 按键2 初始化 */
    GPIO_SetBits(LED_GPIO, LED_R_PIN_MSK | LED_G_PIN_MSK | LED_B_PIN_MSK);      /* 引脚均输出高电平，关闭 LED */

    /* 循环主体 */
    while (1) {
#if BIT_BAND_OPERATION_OUTPUT_EN
        PB_OUT(LED_G_PIN_BIT_NUM) = PIN_LOW;	        /* 使引脚输出低电平, 点亮 LED Green：0引脚 */
        Delay(0x1FFFFF);			                    /* 延时一段时间 */
        PB_OUT(LED_G_PIN_BIT_NUM) = PIN_HIGH;	        /* 使引脚输出高电平，关闭 LED Green：0引脚 */
        Delay(0x1FFFFF);                                /* 延时一段时间 */

        PB_OUT(LED_B_PIN_BIT_NUM) = PIN_LOW;	        /* 使引脚输出低电平, 点亮 LED Blue：1引脚 */
        Delay(0x1FFFFF);			                    /* 延时一段时间 */
        PB_OUT(LED_B_PIN_BIT_NUM) = PIN_HIGH;	        /* 使引脚输出高电平，关闭 LED Blue：1引脚 */
        Delay(0x1FFFFF);                                /* 延时一段时间 */

        PB_OUT(LED_R_PIN_BIT_NUM) = PIN_LOW;	        /* 使引脚输出低电平, 点亮 LED Red：5引脚 */
        Delay(0x1FFFFF);			                    /* 延时一段时间 */
        PB_OUT(LED_R_PIN_BIT_NUM) = PIN_HIGH;	        /* 使引脚输出高电平，关闭 LED Red：5引脚 */
        Delay(0x1FFFFF);                                /* 延时一段时间 */
#elif BIT_BAND_OPERATION_INTPUT_EN
        /* 按键1 按下 */
        if (PA_IN(KEY1_PIN_BIT_NUM) == KEY_ON) {        /* 检测是否有按键按下*/
            while(PA_IN(KEY1_PIN_BIT_NUM) == KEY_ON);   /* 松手检测 */
            LED_TOGGLE(LED_G_PIN_MSK)                   /* LED状态切换 */
        }
        /* 按键2 按下 */
        if (PC_IN(KEY2_PIN_BIT_NUM) == KEY_ON) {        /* 检测是否有按键按下*/
            while(PC_IN(KEY2_PIN_BIT_NUM) == KEY_ON);   /* 松手检测 */
            LED_TOGGLE(LED_G_PIN_MSK)                   /* LED状态切换 */
        }
#else
        /* 按键1 检测 */
        if (KEY_Scan(KEY1_GPIO, KEY1_PIN_MSK) == KEY_ON) {
            LED_TOGGLE(LED_G_PIN_MSK)       /* LED状态切换 */
        }

        /* 按键2 检测 */
        if (KEY_Scan(KEY2_GPIO, KEY2_PIN_MSK) == KEY_ON) {
            LED_TOGGLE(LED_G_PIN_MSK)       /* LED状态切换 */
        }
#endif  /* BIT_BAND_OPERATION_OUTPUT_EN */
    }
}
