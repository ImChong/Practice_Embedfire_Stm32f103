/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:11:00
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 11:56:59
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  :
 */
#include "bsp_rccClkCfg.h"

/**
 * @description: 配置系统时钟为 HSE - 外部高速时钟
 * =================================================================================
 * @return {void}
 */
void HSE_SetSysClk(void) {
    ErrorStatus HSEStatus;

    /* RCC->CR |= ((uint32_t)RCC_CR_HSEON); */
    RCC_HSEConfig(RCC_HSE_ON);                                  /* 使能 HSE - 外部高速时钟 */

    /* HSEStatus = RCC->CR & RCC_CR_HSERDY; */
    HSEStatus = RCC_WaitForHSEStartUp();
    if (HSEStatus == SUCCESS) {
        /* FLASH->ACR */
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);   /* Enable Prefetch Buffer | 使能预取址缓冲区 */
        FLASH_SetLatency(FLASH_Latency_2);                      /* 两个等待状态，当 48MHz < SYSCLK ≤ 72MHz | 国产GD32声称无需等待时间 */

        /* RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1; */
        RCC_HCLKConfig(RCC_SYSCLK_Div1);                        /* AHB clock = SYSCLK = 72 MHz */
        /* RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2; */
        RCC_PCLK1Config(RCC_HCLK_Div2);                         /* APB1 clock = HCLK/2 = 36 MHz */
        /* RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1; */
        RCC_PCLK2Config(RCC_HCLK_Div1);                         /* APB2 clock = HCLK = 72 MHz */
    } else {
        /* 如果 HSE 启动失败，用户可以在这里添加处理错误的代码 */
    }
}