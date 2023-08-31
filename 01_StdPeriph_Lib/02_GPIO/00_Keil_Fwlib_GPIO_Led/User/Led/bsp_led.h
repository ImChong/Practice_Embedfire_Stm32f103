/*
 * @File: bsp_led.h
 * @Created Date: 2023-08-31 11:39:06 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-01 12:33:38 am
 */
#ifndef __BSD_LED_H
#define __BSD_LED_H

#include "stm32f10x.h"

#define LED_GPIO_CLK        RCC_APB2Periph_GPIOB                /* 设置LED的GPIO的时钟 */
#define LED_GPIO            GPIOB                               /* 设置LED的GPIO */
#define LED_R_PIN           GPIO_Pin_5                          /* 红灯引脚 */
#define LED_G_PIN           GPIO_Pin_0                          /* 绿灯引脚 */
#define LED_B_PIN           GPIO_Pin_1                          /* 蓝灯引脚 */

void LED_GPIO_Config(void);

#endif  /* __BSD_LED_H */
