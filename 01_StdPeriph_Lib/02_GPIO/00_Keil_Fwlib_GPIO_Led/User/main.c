/*
 * @File: main.c
 * @Created Date: 2023-08-31 5:17:04 pm
 * @Author: Chong Liu
 * @Brief: Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-09-02 3:03:12 pm
 */
#include "stm32f10x.h"
#include "bsp_led.h"

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
}
