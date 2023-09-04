/*
 * @File: main.c
 * @Created Date: 2023-08-31 5:17:04 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 5:08:48 pm
 */
#include "bsp_led.h"	/* 此头文件将添加 stm32f10x.h */

/* Delay()
 *  Functionality: 延迟函数
 *  Arguments: __IO uint32_t nCount
 *  Return: void
 *  References: [野火]STM32库开发实战指南, ——基于野火指南者开发板
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/* main()
 *  Functionality: 主函数
 *  Arguments: void
 *  Return: int
 *  References: document/website...s
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	LED_GPIO_Config();		/* LED GPIO初始化：默认拉低，此时所有初始化的 LED 灯都会被点亮 */

    GPIO_SetBits(LED_GPIO, LED_R_PIN | LED_G_PIN | LED_B_PIN);		/* 使引脚输出高电平，关闭 LED */
	Delay(0xFFFFFF);												/* 延时一段时间 */

	while (1) {
        LED_SWITCH(LED_G_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Green */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_SWITCH(LED_G_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Green */
        Delay(0x1FFFFF);			/* 延时一段时间 */


		LED_SWITCH(LED_B_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Blue */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_SWITCH(LED_B_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Blue */
        Delay(0x1FFFFF);			/* 延时一段时间 */


		LED_SWITCH(LED_R_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Red */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_SWITCH(LED_R_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Red */
        Delay(0x1FFFFF);			/* 延时一段时间 */
    }
}
