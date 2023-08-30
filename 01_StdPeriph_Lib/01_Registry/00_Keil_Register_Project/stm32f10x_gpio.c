/*
 * @File: stm32f10x_gpio.c
 * @Created Date: 2023-08-28 11:38:14 pm
 * @Author: Chong Liu
 * @Brief: GPIO相关函数
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 10:29:14 pm
 */
#include "stm32f10x_gpio.h"

/* GPIO_SetBits()
 *  Functionality: 为GPIO引脚设置高电平
 *  Arguments: GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References: [野火]STM32库开发实战指南, ——基于野火指南者开发板
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
 *  References: [野火]STM32库开发实战指南, ——基于野火指南者开发板
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
 *  References: [野火]STM32库开发实战指南, ——基于野火指南者开发板
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

                // 向寄存器写入将要配置的引脚的模式
                tmpReg |= (currentMode << pos);

                // 判断是否为下拉输入模式
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
                    // 下拉输入模式, 引脚默认置 0, 对 BRR 寄存器写 1 对引脚置 0
                    GPIOx->BRR = (((uint32_t)0x01) << pinPos);
                // 判断是否为上拉输入模式
                } else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
                    // 上拉输入模式, 引脚默认值为 1, 对 BSRR 寄存器写 1 对引脚置 1
                    GPIOx->BSRR = (((uint32_t)0x01) << pinPos);
                }
            }
        }
        // 把前面处理后的暂存值写入到 CRL 寄存器之中
        GPIOx->CRL = tmpReg;
    }

    /*--------GPIO CRH 寄存器配置 CRH 寄存器控制着高 8 位 IO- -----*/
    // 配置端口高 8 位，即 Pin8~Pin15
    if (GPIO_InitStruct->GPIO_Pin > 0x00FF) {
        // 先备份 CRH 寄存器的值
        tmpReg = GPIOx->CRH;

        // 循环，从 Pin8 开始配对，找出具体的 Pin
        for (pinPos = 0x00; pinPos < 0x08; pinPos++) {
            pos = (((uint32_t)0x01) << (pinPos + 0x08));

            // pos 与输入参数 GPIO_PIN 作位与运算
            currentPin = ((GPIO_InitStruct->GPIO_Pin) & pos);

            // 若 currentPin=pos, 则找到使用的引脚
            if (currentPin == pos) {
                // pinPos 的值左移两位 (乘以 4), 因为寄存器中 4 个位配置一个引脚
                pos = pinPos << 2;

                // 把控制这个引脚的 4 个寄存器位清零，其它寄存器位不变
                pinMask = ((uint32_t)0x0F) << pos;
                tmpReg &= ~pinMask;

                // 向寄存器写入将要配置的引脚的模式
                tmpReg |= (currentMode << pos);

                // 判断是否为下拉输入模式
                if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD) {
                    // 下拉输入模式, 引脚默认置 0, 对 BRR 寄存器写 1 可对引脚置 0
                    GPIOx->BRR = (((uint32_t)0x01) << (pinPos + 0x08));
                // 判断是否为上拉输入模式
                } else if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU) {
                    // 上拉输入模式, 引脚默认值为 1, 对 BSRR 寄存器写 1 可对引脚置
                    GPIOx->BSRR = (((uint32_t)0x01) << (pinPos + 0x08));
                }
            }
        }
        // 把前面处理后的暂存值写入到 CRH 寄存器之中
        GPIOx->CRH = tmpReg;
    }
}
