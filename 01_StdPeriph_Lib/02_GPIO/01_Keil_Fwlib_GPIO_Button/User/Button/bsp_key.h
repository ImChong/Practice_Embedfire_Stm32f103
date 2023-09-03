/*
 * @File: bsp_key.h
 * @Created Date: 2023-09-02 5:39:10 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-03 10:01:17 pm
 */
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"      /* 此头文件将添加 stm32f10x_conf.h - 管理所有外设的头文件 */

#define KEY1_GPIO_CLK       RCC_APB2Periph_GPIOA        /* 设置KEY的GPIO的时钟使能寄存器地址 */
#define KEY1_GPIO           GPIOA                       /* 设置KEY的GPIO寄存器地址 */
#define KEY1_PIN            GPIO_Pin_0                  /* KEY引脚寄存器地址 */

#define KEY2_GPIO_CLK       RCC_APB2Periph_GPIOC        /* 设置KEY的GPIO的时钟使能寄存器地址 */
#define KEY2_GPIO           GPIOC                       /* 设置KEY的GPIO寄存器地址 */
#define KEY2_PIN            GPIO_Pin_13                 /* KEY引脚寄存器地址 */


#endif  /* __BSP_KEY_H */
