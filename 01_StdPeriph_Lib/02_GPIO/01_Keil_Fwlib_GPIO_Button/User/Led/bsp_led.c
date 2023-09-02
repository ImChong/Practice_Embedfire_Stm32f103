/*
 * @File: bsp_led.c
 * @Created Date: 2023-08-31 11:38:57 pm
 * @Author: Chong Liu
 * @Brief: bsp - board support package 板级支持包
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 3:05:58 pm
 */
#include "bsp_led.h"    /* 此头文件将添加 stm32f10x.h */

/* LED_GPIO_Config()
 *  Functionality: LED GPIO初始化
 *  Arguments: void
 *  Return: void
 *  References: LED GPIO 初始化
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void LED_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;                                /* GPIO 端口初始化结构体 */

    RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LED_R_PIN | LED_G_PIN | LED_B_PIN;    /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                    /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                   /* 设置输出速率为 50MHZ */
    GPIO_Init(LED_GPIO, &GPIO_InitStructure);
}
