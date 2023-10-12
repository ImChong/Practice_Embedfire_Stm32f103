/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\Led\bsp_led.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:29:59
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-09 17:55:26
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package: LED 相关函数源文件
 */
#include "bsp_led.h"    /* 此头文件将添加 stm32f10x.h */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: LED 的 GPIO 初始化
 * =================================================================================
 * @return {void}
 */
void LED_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;                                            /* GPIO 端口初始化结构体 */
    RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);                                   /* APB2 GPIOB 时钟使能 */

    GPIO_InitStructure.GPIO_Pin = LED_R_PIN_MSK | LED_G_PIN_MSK | LED_B_PIN_MSK;    /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                                /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                               /* 设置输出速率为 50MHZ */
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);

    GPIO_SetBits(LED_GPIO, LED_R_PIN_MSK | LED_G_PIN_MSK | LED_B_PIN_MSK);		    /* 使引脚输出高电平，关闭 LED */
}
