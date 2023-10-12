/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:12:51
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 09:08:40
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package: RCC 相关函数头文件
 */
#ifndef __BSP_RCCCLKCFG_H
#define __BSP_RCCCLKCFG_H

#include "stm32f10x.h"

/**********************************************************************************/
/*                                                                                */
/*                                MACRO CONSTANTS                                 */
/*                                                                                */
/**********************************************************************************/
#define RCC_GPIO_CLK            RCC_APB2Periph_GPIOA        /* 设置LED的GPIO的时钟使能寄存器地址 */
#define RCC_GPIO                GPIOA                       /* 设置LED的GPIO寄存器地址 */
#define RCC_PIN_MSK           GPIO_Pin_1                  /* 蓝灯引脚寄存器地址 */

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
void HSE_SetSysClk(uint32_t RCC_PLLMul_x);
void MCO_GPIO_Config(void);

#endif  /* __BSP_RCCCLKCFG_H */
