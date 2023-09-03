/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\Button\bsp_key.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:39:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 00:02:49
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
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

void KEY_GPIO_Config(uint32_t GPIO_Clock, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif  /* __BSP_KEY_H */
