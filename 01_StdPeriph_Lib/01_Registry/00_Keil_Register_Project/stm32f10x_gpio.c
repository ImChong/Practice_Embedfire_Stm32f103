/*
 * @File: stm32f10x_gpio.c
 * @Created Date: Monday, August 28th 2023, 11:38:14 pm
 * @Author: Chong Liu
 * @brief Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - Tuesday, August 29th 2023, 1:42:43 am
 */
#include "stm32f10x_gpio.h"

/* GPIO_SetBits()
 *  Functionality: 为GPIO引脚设置高电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References:
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
 *  References:
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIOx->BRR |= GPIO_Pin;
}
