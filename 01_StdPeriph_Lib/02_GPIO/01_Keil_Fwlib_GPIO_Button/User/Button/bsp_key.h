/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\Button\bsp_key.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:39:10
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 22:24:22
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package：按键相关函数头文件
 */
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"      /* 此头文件将添加 stm32f10x_conf.h - 管理所有外设的头文件 */

#define KEY1_GPIO_CLK       RCC_APB2Periph_GPIOA        /* 设置 KEY 的 GPIO 的时钟使能寄存器地址 */
#define KEY1_GPIO           GPIOA                       /* 设置 KEY 的 GPIO 寄存器地址 */
#define KEY1_PIN_MSK        GPIO_Pin_0                  /* KEY 引脚寄存器地址 */
#define KEY1_PIN_BIT_NUM    0                           /* KEY 引脚编号 */

#define KEY2_GPIO_CLK       RCC_APB2Periph_GPIOC        /* 设置 KEY 的 GPIO 的时钟使能寄存器地址 */
#define KEY2_GPIO           GPIOC                       /* 设置 KEY 的 GPIO 寄存器地址 */
#define KEY2_PIN_MSK        GPIO_Pin_13                 /* KEY 引脚寄存器地址 */
#define KEY2_PIN_BIT_NUM    1                           /* KEY 引脚编号 */

#define KEY_ON  1
#define KEY_OFF 0

void KEY_GPIO_Config(uint32_t RCC_GPIO_Clock, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t KEY_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif  /* __BSP_KEY_H */
