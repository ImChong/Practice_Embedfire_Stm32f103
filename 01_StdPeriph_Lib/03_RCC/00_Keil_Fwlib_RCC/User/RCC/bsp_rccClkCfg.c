/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:11:00
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-08 11:45:20
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

    RCC_HSEConfig(RCC_HSE_ON);                                  /* 使能 HSE - 外部高速时钟 */

    HSEStatus = RCC_WaitForHSEStartUp();
    if (HSEStatus == SUCCESS) {
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);
    } else {
        /* 如果 HSE 启动失败，用户可以在这里添加处理错误的代码 */
    }
}