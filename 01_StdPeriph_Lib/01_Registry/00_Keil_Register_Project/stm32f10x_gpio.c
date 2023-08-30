/*
 * @File: stm32f10x_gpio.c
 * @Created Date: 2023-08-28 11:38:14 pm
 * @Author: Chong Liu
 * @Brief: GPIO相关函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 4:32:27 pm
 */
#include "stm32f10x_gpio.h"

/* GPIO_SetBits()
 *  Functionality: 为GPIO引脚设置高电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIOx->BSRR |= GPIO_Pin;
}

/* GPIO_ResetBits()
 *  Functionality: 为GPIO引脚设置低电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIOx->BRR |= GPIO_Pin;
}

/* GPIO_Init()
 *  Functionality: GPIO初始化，初始化引脚模式
 *  Arguments: GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct) {
    uint32_t currentmode =0x00, currentpin = 0x00, pinpos = 0x00, pos = 0x00;
    uint32_t tmpreg = 0x00, pinmask = 0x00;
}