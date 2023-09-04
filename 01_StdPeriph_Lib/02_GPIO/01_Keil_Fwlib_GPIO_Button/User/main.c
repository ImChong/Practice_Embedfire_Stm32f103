/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:29:59
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 22:18:09
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
#define BIT_BAND_OPERATION_INTPUT_EN 1     /* 是否开启位带操作相关代码 */

#define GPIOB_ODR_ADDR          (GPIOB_BASE + 0x0C)
#define PB_OUT(bitNum)          *(unsigned int *)((GPIOB_ODR_ADDR & 0xF0000000)+0x02000000+((GPIOB_ODR_ADDR & 0x00FFFFFF)<<5)+(bitNum<<2))
#define PA_IN(bitNum)           *(unsigned int *)((GPIOB_ODR_ADDR & 0xF0000000)+0x02000000+((GPIOB_ODR_ADDR & 0x00FFFFFF)<<5)+(bitNum<<2))
#define BITBAND(addr, bitNum)   ((addr & 0xF0000000)+0x02000000+((addr & 0x00FFFFFF)<<5)+(bitNum<<2))     /* 把“位带地址 + 位序号”转换成别名地址的宏 */

/**
 * @description:
 * =================================================================================
 * @param {__IO uint32_t} nCount
 * @return {*}
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/**
 * @description: 主函数
 * =================================================================================
 * @return {*}
 */
int main(void)
{
    /* 来到这里的时候，系统的时钟已经被配置成72M */
    LED_GPIO_Config();		/* LED GPIO初始化：默认输出拉低，此时所有初始化的 LED 灯都会被点亮 */
    KEY_GPIO_Config(KEY1_GPIO_CLK, KEY1_GPIO, KEY1_PIN);            /* 按键1 初始化 */
    KEY_GPIO_Config(KEY2_GPIO_CLK, KEY2_GPIO, KEY2_PIN);            /* 按键2 初始化 */
    GPIO_SetBits(LED_GPIO, LED_R_PIN_MSK | LED_G_PIN_MSK | LED_B_PIN_MSK);      /* 使引脚输出高电平，关闭 LED */

    /* 循环主体 */
    while (1) {
#if BIT_BAND_OPERATION_OUTPUT_EN
        PB_OUT(LED_G_PIN_BIT_NUM) = LED_ON;	            /* 使引脚输出低电平, 点亮 LED Green：0引脚 */
        Delay(0x1FFFFF);			                    /* 延时一段时间 */

        PB_OUT(LED_G_PIN_BIT_NUM) = LED_OFF;	        /* 使引脚输出高电平，关闭 LED Green：0引脚 */
        Delay(0x1FFFFF);                                /* 延时一段时间 */
#elif BIT_BAND_OPERATION_INTPUT_EN


#else
        /* 按键1 检测 */
        if (KEY_Scan(KEY1_GPIO, KEY1_PIN) == KEY_ON) {
            LED_TOGGLE(LED_G_PIN_MSK)       /* LED状态切换 */
        }

        /* 按键2 检测 */
        if (KEY_Scan(KEY2_GPIO, KEY2_PIN) == KEY_ON) {
            LED_TOGGLE(LED_G_PIN_MSK)       /* LED状态切换 */
        }
#endif  /* BIT_BAND_OPERATION_EN */
    }
}
