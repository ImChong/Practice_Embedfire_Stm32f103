/*
 * @File: stm32f10x_gpio.c
 * @Created Date: 2023-08-28 11:38:14 pm
 * @Author: Chong Liu
 * @Brief: GPIO相关函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 6:44:37 pm
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
    uint32_t currentMode =0x00, currentPin = 0x00, pinPos = 0x00, pos = 0x00;
    uint32_t tmpReg = 0x00, pinMask = 0x00;

    /*---------------- GPIO 模式配置-------------------*/
    // 把输入参数GPIO_Mode 的低四位暂存在currentMode
    currentMode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x0F);

    // bit4 是1 表示输出，bit4 是0 则是输入
    // 判断bit4 是1 还是0，即首选判断是输入还是输出模式
    if ((((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x10)) != 0x00) {
        // 输出模式则要设置输出速度
        currentMode |= (uint32_t)GPIO_InitStruct->GPIO_Speed;
    }

    /*-----GPIO CRL 寄存器配置CRL 寄存器控制着低8 位IO- ----*/
    // 配置端口低8 位，即Pin0~Pin7
    if (((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00) {

    }
}