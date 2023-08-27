/* 用来存放 STM32 寄存器映射的代码 */

/* 外设基地址 */
#define PERIPH_BASE           ((uint32_t)0x40000000)    /* NOTE: Peripheral base address in the alias region */

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)