/*
 * @File: bsp_key.c
 * @Created Date: 2023-09-02 5:39:04 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-03 10:42:02 pm
 */
#include "bsp_key.h"    /* 此头文件将添加 stm32f10x.h */

/* KEY_GPIO_Config()
 *  Functionality: description...
 *  Arguments: uint32_t GPIO_Clock, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void KEY_GPIO_Config(uint32_t GPIO_Clock, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    GPIO_InitTypeDef GPIO_InitStructure;                                /* GPIO 端口初始化结构体 */
    RCC_APB2PeriphClockCmd(GPIO_Clock, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;                             /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;               /* 设置引脚的输出类型为浮空输入：硬件已外部下拉 */
    /* 输入无需设置速率 */
    GPIO_Init(GPIOx, &GPIO_InitStructure);
}