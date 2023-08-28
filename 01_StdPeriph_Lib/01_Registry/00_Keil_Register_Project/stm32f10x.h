/*
 * @File: stm32f10x.h
 * @Created Date: Sunday, August 27th 2023, 3:48:50 pm
 * @Author: Chong Liu
 * @brief Description of what this file does
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - Tuesday, August 29th 2023, 1:43:07 am
 */
#ifndef __STM32F10X_H   /* 防止重复包含头文件 */
#define __STM32F10X_H

/* 用来存放 STM32 寄存器映射的代码 */
#define PERIPH_BASE         ((unsigned int)0x40000000)            /* 片上外设基地址 */

#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x10000)               /* 总线基地址，GPIO 都挂载到 APB2 上 */
#define AHBPERIPH_BASE      (PERIPH_BASE + 0x20000)

#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)            /* GPIOB 外设基地址 */
#define RCC_BASE            (AHBPERIPH_BASE + 0x1000)             /* RCC 外设基地址 */
// #define RCC_APB2ENR         *(unsigned int *)(RCC_BASE + 0x18)     /* RCC 的 AHB 时钟使能寄存器地址, 强制转换成指针 */

/* GPIOB 寄存器地址, 强制转换成指针 */
// #define GPIOB_CRL           *(unsigned int*)(GPIOB_BASE+0x00)
// #define GPIOB_CRH           *(unsigned int*)(GPIOB_BASE+0x04)
// #define GPIOB_IDR           *(unsigned int*)(GPIOB_BASE+0x08)
// #define GPIOB_ODR           *(unsigned int*)(GPIOB_BASE+0x0C)
// #define GPIOB_BSRR          *(unsigned int*)(GPIOB_BASE+0x10)
// #define GPIOB_BRR           *(unsigned int*)(GPIOB_BASE+0x14)
// #define GPIOB_LCKR          *(unsigned int*)(GPIOB_BASE+0x18)

// 寄存器的值常常是芯片外设自动更改的，即使 CPU 没有执行程序，也有可能发生变化
// 编译器有可能会对没有执行程序的变量进行优化
// volatile 表示易变的变量，防止编译器优化
#define __IO volatile
typedef unsigned int    uint32_t;   /* 无符号 32 位变量 */
typedef unsigned short  uint16_t;   /* 无符号 16 位变量 */

/*  RCC 寄存器结构体定义 */
typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t CFGR;
    __IO uint32_t CIR;
    __IO uint32_t APB2RSTR;
    __IO uint32_t APB1RSTR;
    __IO uint32_t AHBENR;
    __IO uint32_t APB2ENR;
    __IO uint32_t APB1ENR;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
} RCC_TypeDef;

#define RCC     ((RCC_TypeDef *)RCC_BASE)

/*  GPIO 寄存器结构体定义 */
typedef struct {
    __IO uint32_t CRL; /*GPIO 端口配置低寄存器 地址偏移: 0x00 */
    __IO uint32_t CRH; /*GPIO 端口配置高寄存器 地址偏移: 0x04 */
    __IO uint32_t IDR; /*GPIO 数据输入寄存器 地址偏移: 0x08 */
    __IO uint32_t ODR; /*GPIO 数据输出寄存器 地址偏移: 0x0C */
    __IO uint32_t BSRR; /*GPIO 位设置/清除寄存器 地址偏移: 0x10 */
    __IO uint32_t BRR; /*GPIO 端口位清除寄存器 地址偏移: 0x14 */
    __IO uint32_t LCKR; /*GPIO 端口配置锁定寄存器 地址偏移: 0x18 */
} GPIO_TypeDef;

#define GPIOB   ((GPIO_TypeDef *)GPIOB_BASE)

#endif /* __STM32F10X_H */
