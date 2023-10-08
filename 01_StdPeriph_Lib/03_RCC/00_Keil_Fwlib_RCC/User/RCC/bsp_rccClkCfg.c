/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:11:00
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 11:53:45
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
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);

        /* RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1; */
        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        /* RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2; */
        RCC_PCLK1Config(RCC_HCLK_Div2);
        /* RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1; */
        RCC_PCLK2Config(RCC_HCLK_Div1);
    } else {
        /* 如果 HSE 启动失败，用户可以在这里添加处理错误的代码 */
    }
}