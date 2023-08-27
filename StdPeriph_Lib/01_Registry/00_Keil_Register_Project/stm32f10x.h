/* 用来存放 STM32 寄存器映射的代码 */

/* 外设基地址 */
#define PERIPH_BASE           ((uint32_t)0x40000000)    /* Peripheral base address in the alias region */

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define RCC_APB2ENR           (unsigned int *)(RCC_BASE + 0x18)     /* 将地址转换为指针 */