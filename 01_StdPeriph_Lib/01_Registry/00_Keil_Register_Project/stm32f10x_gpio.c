/*
 * @File: stm32f10x_gpio.c
 * @Created Date: 2023-08-28 11:38:14 pm
 * @Author: Chong Liu
 * @Brief: GPIO相关函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 9:43:13 pm
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
        // 先备份 CRL 寄存器的值
        tmpReg = GPIOx->CRL;
        // 循环，从 Pin0 开始配对，找出具体的 Pin
        for (pinPos = 0x00; pinPos < 0x08; pinPos++) {
            // pos 的值为 1 左移 pinPos 位
            pos = ((uint32_t)0x01) << pinPos;

            // 令 pos 与输入参数 GPIO_PIN 作位与运算
            currentPin = (GPIO_InitStruct->GPIO_Pin) & pos;

            //若 currentPin=pos, 则找到使用的引脚
            if (currentPin == pos) {
                //pinPos 的值左移两位 (乘以 4), 因为寄存器中 4 个位配置一个引脚
                pos = pinPos << 2;
                //把控制这个引脚的 4 个寄存器位清零，其它寄存器位不变
                pinMask = ((uint32_t)0x0F) << pos;
                tmpReg &= ~pinMask;
            }
        }
    }
}