/*
 * @FilePath     : \00_Keil_Fwlib_RCC\User\RCC\bsp_rccClkCfg.c
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-06 23:11:00
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2023-10-12 09:18:51
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : BSP - Board Support Package: RCC 相关函数源文件
 */
#include "bsp_rccClkCfg.h"

/**********************************************************************************/
/*                                                                                */
/*                                 UTILITY FUNCTIONS                              */
/*                                                                                */
/**********************************************************************************/
/**
 * @description: 配置系统时钟为 HSE - 外部高速时钟
 * =================================================================================
 * @param {uint32_t} RCC_PLLMul_x   设置 PLL 倍频因子 - specifies the PLL multiplication factor.
 * @return {void}
 */
void HSE_SetSysClk(uint32_t RCC_PLLMul_x) {
    ErrorStatus HSEStatus;                                      /* 外部高速时钟使能状态 */
    RCC_DeInit();                                               /* 把 RCC 寄存器复位成复位值 */

    /* 使能 HSE */
    RCC_HSEConfig(RCC_HSE_ON);                                  /* 使能 HSE - 外部高速时钟 */
    HSEStatus = RCC_WaitForHSEStartUp();

    if (HSEStatus == SUCCESS) {
        /* 使能预取指 */
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);   /* Enable Prefetch Buffer | 使能预取指缓冲区 */
        FLASH_SetLatency(FLASH_Latency_2);                      /* 两个等待状态，当 48MHz < SYSCLK ≤ 72MHz | 国产GD32声称无需等待时间 */

        RCC_HCLKConfig(RCC_SYSCLK_Div1);                        /* AHB clock = SYSCLK = 72 MHz */
        RCC_PCLK1Config(RCC_HCLK_Div2);                         /* APB1 clock = HCLK/2 = 36 MHz */
        RCC_PCLK2Config(RCC_HCLK_Div1);                         /* APB2 clock = HCLK = 72 MHz */

        /* 超频 */
        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);    /* PLLCLK = HSE (8 MHz) * 9 (修改为参数 RCC_PLLMul_x 实现自定义倍频) = 72 MHz */
        RCC_PLLCmd(ENABLE);                                     /* PLL 使能 */

        /* 等待 PLL 稳定 */
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) {}  /* 等待 PLL 时钟就绪标志 (PLL clock ready flag) */
            /* 选择系统时钟 */
            RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);          /* PLL 作为系统时钟源 */
            while (RCC_GetSYSCLKSource() != 0x08) {}
    } else {
        /* 如果 HSE 启动失败，用户可以在这里添加处理错误的代码 */
    }
}

/**
 * @description: 主时钟输出初始化
 * =================================================================================
 * @return {void}
 */
void MCO_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;                        /* GPIO 端口初始化结构体 */
    RCC_APB2PeriphClockCmd(MCO_GPIO_CLK, ENABLE);               /* APB2 GPIOB 时钟使能 */

    GPIO_InitStructure.GPIO_Pin = MCO_PIN_MSK;                  /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;            /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;           /* 设置输出速率为 50MHZ */
    GPIO_Init(MCO_GPIO, &GPIO_InitStructure);

    GPIO_SetBits(MCO_GPIO, MCO_PIN_MSK);		                /* 使引脚输出高电平，关闭 LED */
}
