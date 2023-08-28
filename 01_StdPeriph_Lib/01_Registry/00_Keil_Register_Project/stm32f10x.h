/* 用来存放 STM32 寄存器映射的代码 */
#define PERIPH_BASE         ((unsigned int)0x40000000)            /* 片上外设基地址 */

#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x10000)               /* 总线基地址，GPIO 都挂载到 APB2 上 */
#define AHBPERIPH_BASE      (PERIPH_BASE + 0x20000)

#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)            /* GPIOB 外设基地址 */
#define RCC_BASE            (AHBPERIPH_BASE + 0x1000)             /* RCC 外设基地址 */
#define RCC_APB2ENR         *(unsigned int *)(RCC_BASE + 0x18)     /* RCC 的 AHB 时钟使能寄存器地址, 强制转换成指针 */

/* GPIOB 寄存器地址, 强制转换成指针 */
#define GPIOB_CRL           *(unsigned int*)(GPIOB_BASE+0x00)
#define GPIOB_CRH           *(unsigned int*)(GPIOB_BASE+0x04)
#define GPIOB_IDR           *(unsigned int*)(GPIOB_BASE+0x08)
#define GPIOB_ODR           *(unsigned int*)(GPIOB_BASE+0x0C)
#define GPIOB_BSRR          *(unsigned int*)(GPIOB_BASE+0x10)
#define GPIOB_BRR           *(unsigned int*)(GPIOB_BASE+0x14)
#define GPIOB_LCKR          *(unsigned int*)(GPIOB_BASE+0x18)

typedef unsigned int    uint32_t;   /* 无符号 32 位变量 */
typedef unsigned short  uint16_t;   /* 无符号 16 位变量 */

/* GPIO 寄存器列表 */
typedef struct {
    uint32_t CRL; /*GPIO 端口配置低寄存器 地址偏移: 0x00 */
    uint32_t CRH; /*GPIO 端口配置高寄存器 地址偏移: 0x04 */
    uint32_t IDR; /*GPIO 数据输入寄存器 地址偏移: 0x08 */
    uint32_t ODR; /*GPIO 数据输出寄存器 地址偏移: 0x0C */
    uint32_t BSRR; /*GPIO 位设置/清除寄存器 地址偏移: 0x10 */
    uint32_t BRR; /*GPIO 端口位清除寄存器 地址偏移: 0x14 */
    uint32_t LCKR; /*GPIO 端口配置锁定寄存器 地址偏移: 0x18 */
} GPIO_TypeDef;

#define GPIOB   ((GPIO_TypeDef *)GPIOB_BASE)
