/*
 * @File: bsp_key.c
 * @Created Date: 2023-09-02 5:39:04 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-03 9:57:39 pm
 */
#include "bsp_key.h"    /* 此头文件将添加 stm32f10x.h */

/* functionName()
 *  Functionality: description...
 *  Arguments: arguments...
 *  Return: possibleReturnValues
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void KEY_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;                                /* GPIO 端口初始化结构体 */
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = KEY1_PIN;                             /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;               /* 设置引脚的输出类型为浮空输入：硬件已外部下拉 */
    /* 输入无需设置速率 */
    GPIO_Init(KEY1_GPIO, &GPIO_InitStructure);
}