/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\main.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-09-01 20:07:07
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 09:16:33
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : 主函数文件
 */
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_rccClkCfg.h"

/**********************************************************************************/
/*                                                                                */
/*                                 HELPER FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 延迟函数
 * =================================================================================
 * @param {__IO uint32_t} nCount
 * @return {void}
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/**********************************************************************************/
/*                                                                                */
/*                                  MAIN FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 主函数
 * =================================================================================
 * @return {int}	程序运行状态
 */
int main(void)
{
	/* 来到这里的时候，系统的时钟已经被配置成72M。*/
	HSE_SetSysClk(RCC_PLLMul_16);					/* 16 * 8 MHz = 128 MHz */

	MCO_GPIO_Config();								/* 初始化 MCO GPIO */
	LED_GPIO_Config();								/* 初始化 LED GPIO */

	while(1) {										/* 主任务循环 */
		LED_SWITCH(LED_G_PIN_MSK, LED_ON)				/* 使引脚输出低电平, 点亮 LED Green */
        Delay(0x1FFFFF);								/* 延时一段时间 */
        LED_SWITCH(LED_G_PIN_MSK, LED_OFF)				/* 使引脚输出高电平，关闭 LED Green */
        Delay(0x1FFFFF);								/* 延时一段时间 */
	}
}
