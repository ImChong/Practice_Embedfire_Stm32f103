/* 用来存放 STM32 寄存器映射的代码 */

#define PERIPH_BASE           ((unsigned int)0x40000000)            /* 片上外设基地址 */

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)               /* 总线基地址，GPIO 都挂载到 APB2 上 */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)            /* GPIOB 外设基地址 */
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)             /* RCC 外设基地址 */
#define RCC_APB2ENR           (unsigned int *)(RCC_BASE + 0x18)     /* RCC 的 AHB 时钟使能寄存器地址, 强制转换成指针 */