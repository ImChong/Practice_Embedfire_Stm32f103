/*
 * @FilePath     : \01_Keil_Fwlib_GPIO_Button\User\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-02 17:29:59
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-09-04 09:29:48
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : STM32F103 指南者按键检测
 * https://www.bilibili.com/video/BV1Xs411g7Aj/?p=19&spm_id_from=pageDriver&vd_source=75275452d1d334b4d80721d4823e4631
 */
#include "bsp_led.h"	/* 此头文件将添加 stm32f10x.h */
#include "bsp_key.h"	/* 此头文件将添加 stm32f10x.h */

/**
 * @description:
 * =================================================================================
 * @param {__IO uint32_t} nCount
 * @return {*}
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/**
 * @description:
 * =================================================================================
 * @return {*}
 */
int main(void)
{
	/* 来到这里的时候，系统的时钟已经被配置成72M */
	LED_GPIO_Config();		/* LED GPIO初始化：默认拉低，此时所有初始化的 LED 灯都会被点亮 */

    GPIO_SetBits(LED_GPIO, LED_R_PIN | LED_G_PIN | LED_B_PIN);		/* 使引脚输出高电平，关闭 LED */
	Delay(0xFFFFFF);												/* 延时一段时间 */

	while (1) {
        LED_TOGGLE(LED_G_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Green */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_TOGGLE(LED_G_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Green */
        Delay(0x1FFFFF);			/* 延时一段时间 */


		LED_TOGGLE(LED_B_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Blue */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_TOGGLE(LED_B_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Blue */
        Delay(0x1FFFFF);			/* 延时一段时间 */


		LED_TOGGLE(LED_R_PIN, ON)	/* 使引脚输出低电平, 点亮 LED Red */
        Delay(0x1FFFFF);			/* 延时一段时间 */
        LED_TOGGLE(LED_R_PIN, OFF)	/* 使引脚输出高电平，关闭 LED Red */
        Delay(0x1FFFFF);			/* 延时一段时间 */
    }
}
