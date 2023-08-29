/*
 * @File: stm32f10x_gpio.h
 * @Created Date: 2023-08-28 11:38:06 pm
 * @Author: Chong Liu
 * @brief Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 12:49:03 am
 */
#ifndef __STM32F10X_GPIO_H  /* 防止重复包含头文件 */
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"

/*GPIO 引脚号定义 */
#define GPIO_Pin_0      ((uint16_t)0x0001)      /*!< 选择 Pin0 (1<<0)   (00000000 00000001)b */
#define GPIO_Pin_1      ((uint16_t)0x0002)      /*!< 选择 Pin1 (1<<1)   (00000000 00000010)b */
#define GPIO_Pin_2      ((uint16_t)0x0004)      /*!< 选择 Pin2 (1<<2)   (00000000 00000100)b */
#define GPIO_Pin_3      ((uint16_t)0x0008)      /*!< 选择 Pin3 (1<<3)   (00000000 00001000)b */
#define GPIO_Pin_4      ((uint16_t)0x0010)      /*!< 选择 Pin4          (00000000 00010000)b */
#define GPIO_Pin_5      ((uint16_t)0x0020)      /*!< 选择 Pin5          (00000000 00100000)b */
#define GPIO_Pin_6      ((uint16_t)0x0040)      /*!< 选择 Pin6          (00000000 01000000)b */
#define GPIO_Pin_7      ((uint16_t)0x0080)      /*!< 选择 Pin7          (00000000 10000000)b */
#define GPIO_Pin_8      ((uint16_t)0x0100)      /*!< 选择 Pin8          (00000001 00000000)b */
#define GPIO_Pin_9      ((uint16_t)0x0200)      /*!< 选择 Pin9          (00000010 00000000)b */
#define GPIO_Pin_10     ((uint16_t)0x0400)      /*!< 选择 Pin10         (00000100 00000000)b */
#define GPIO_Pin_11     ((uint16_t)0x0800)      /*!< 选择 Pin11         (00001000 00000000)b */
#define GPIO_Pin_12     ((uint16_t)0x1000)      /*!< 选择 Pin12         (00010000 00000000)b */
#define GPIO_Pin_13     ((uint16_t)0x2000)      /*!< 选择 Pin13         (00100000 00000000)b */
#define GPIO_Pin_14     ((uint16_t)0x4000)      /*!< 选择 Pin14         (01000000 00000000)b */
#define GPIO_Pin_15     ((uint16_t)0x8000)      /*!< 选择 Pin15         (10000000 00000000)b */
#define GPIO_Pin_All    ((uint16_t)0xFFFF)      /*!< 选择全部引脚        (11111111 11111111)b */

typedef struct {

} GPIO_InitTypeDef;

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif  /* __STM32F10X_GPIO_H */
