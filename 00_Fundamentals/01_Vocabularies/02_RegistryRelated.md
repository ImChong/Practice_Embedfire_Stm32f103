# 1. 寄存器相关

- [1. 寄存器相关](#1-寄存器相关)
  - [1.1. 寄存器（Register）](#11-寄存器register)
  - [1.2. FSMC（Flexible static memory controller）](#12-fsmcflexible-static-memory-controller)
  - [1.3. DMA（Direct Memory Access）](#13-dmadirect-memory-access)
  - [1.4. AHB（Advanced High-performance Bus）](#14-ahbadvanced-high-performance-bus)
  - [1.5. APB（Advanced Peripheral Bus）](#15-apbadvanced-peripheral-bus)
  - [1.6. RCC（Reset and Clock Control）](#16-rccreset-and-clock-control)
  - [1.7. SDIO（Secure Digital Input Output）](#17-sdiosecure-digital-input-output)
  - [1.8. 桥接器（Bridges）](#18-桥接器bridges)
  - [1.9. CRC（Cyclic Redundancy Check）](#19-crccyclic-redundancy-check)
  - [1.10. GPIO（General-Purpose Input/Output）](#110-gpiogeneral-purpose-inputoutput)
  - [1.11. GPIOx\_ODR（Output Data Register）](#111-gpiox_odroutput-data-register)
  - [1.12. GPIOx\_IDR（Input Data Register）](#112-gpiox_idrinput-data-register)
  - [1.13. GPIOx\_CRL（Configuration Register Low）](#113-gpiox_crlconfiguration-register-low)
  - [1.14. GPIOx\_CRH（Configuration Register High）](#114-gpiox_crhconfiguration-register-high)
  - [1.15. GPIOx\_BSRR（Bit Set/Reset Register）](#115-gpiox_bsrrbit-setreset-register)
  - [1.16. GPIOx\_BRR（Bit Reset Register）](#116-gpiox_brrbit-reset-register)
  - [1.17. GPIOx\_LCKR（Lock Register）](#117-gpiox_lckrlock-register)
  - [1.18. HSI（High-Speed Internal）](#118-hsihigh-speed-internal)
  - [1.19. 推挽输出（Push-Pull）](#119-推挽输出push-pull)
  - [1.20. 开漏输出（Open-Drain）](#120-开漏输出open-drain)

## 1.1. 寄存器（Register）
> 在计算机体系结构和嵌入式系统中，寄存器是一种小型的、高速的临时存储器组件，用于存储和处理计算机程序和数据。寄存器通常直接集成在中央处理器（CPU）内部，用于执行指令和进行运算。
>
> 在计算机中，寄存器是一种用于存储和快速访问数据的硬件设备。位是二进制数中的单个数字，可以是0或1。在寄存器中，每个位都可以存储一个二进制数字。因此，寄存器可以用于存储和操作二进制数据。
> 
> 在嵌入式系统中，寄存器通常用于控制硬件设备。例如，一个寄存器可以控制一个 GPIO 引脚的状态。为了控制特定的位，我们可以使用位运算符（例如按位与、按位或、按位异或）来读取、修改和写入寄存器中的数据。
>
> 例如，假设我们有一个 32 位的寄存器 R，并且我们想要将 R 的第 5 个位设置为 1。我们可以使用按位或运算符将 R 的第 5 个位设置为 1，而不影响其他位。具体来说，我们可以构造一个值为 0x20 的二进制数（即只有第 5 个位为 1），然后将其与 R 进行按位或运算。
>
> 如果我们想要清除 R 的第 5 个位（即将其设置为 0），我们可以使用按位与运算符。具体来说，我们可以构造一个值为 0xFFFFFFDF 的二进制数（即只有第 5 个位为 0），然后将其与 R 进行按位与运算。

## 1.2. FSMC（Flexible static memory controller）
> FSMC 的英文全称是 Flexible static memory controller，叫灵活的静态的存储器控制器，是STM32F10xx 中一个很有特色的外设，通过FSMC，我们可以扩展内存，如外部的SRAM，NAND-FLASH 和NORFLASH。但有一点我们要注意的是，FSMC 只能扩展静态的内存，即名称里面的S：static，不能是动态的内存，比如SDRAM 就不能扩展。

## 1.3. DMA（Direct Memory Access）
> DMA（Direct Memory Access，直接内存访问）是一种计算机和嵌入式系统中用于高速数据传输的技术。它允许外部设备或内部模块直接访问系统内存，而无需CPU的直接干预。这种方式可以显著提高数据传输速度，减轻CPU的负担，同时提高系统性能。

## 1.4. AHB（Advanced High-performance Bus）
> AHB（Advanced High-performance Bus，高级高性能总线）。AHB是一种高性能总线协议，通常用于连接高性能组件，如处理器核心、高速缓存和其他高带宽要求的组件。AHB总线使用分级的“主从”体系结构，支持高性能传输和多主设备。

## 1.5. APB（Advanced Peripheral Bus）
> APB（Advanced Peripheral Bus）。APB是一种较低性能、较低速度的总线，主要用于连接外围设备。它适用于不需要高速数据传输的外设，如定时器、GPIO（通用输入/输出口）、串口等。APB总线可以分为APB1和APB2两个子总线。
> ### APB1（Advanced Peripheral Bus 1）
> - 速度和性能：APB1总线的速度相对较低，通常用于连接一些低速外设。
> - 外设连接：APB1总线连接了一些相对不需要高速访问的外设，如低速串口、定时器、看门狗定时器等。
> - 分频器：APB1总线的时钟源可以使用分频器进行分频，以获取所需的时钟频率。
> ### APB2（Advanced Peripheral Bus 2）
> - 速度和性能：APB2总线的速度相对较高，适用于连接一些需要更高性能的外设。
> - 外设连接：APB2总线连接了一些需要较高性能访问的外设，如高速串口、USB等。
> - 分频器：APB2总线的时钟源可以使用分频器进行分频，以获取所需的时钟频率。

## 1.6. RCC（Reset and Clock Control）
> RCC代表的是Reset and Clock Control，即复位与时钟控制模块。它是用于配置和控制微控制器内部时钟源和外设的重要模块。通过RCC模块，开发者可以管理微控制器的时钟设置，以满足不同应用的需求。
> RCC模块的主要功能包括：
> - 时钟源选择：RCC模块允许开发者选择不同的时钟源，如内部振荡器、外部晶振、PLL（Phase-Locked Loop）等。这些时钟源可以用于驱动不同的系统组件和外设。
> - 时钟分频：RCC模块允许开发者对时钟进行分频，以获取所需的时钟频率。分频可以用于降低时钟频率以节省功耗，或者将时钟频率提高以满足高性能要求。
> - 时钟使能和失能：通过RCC模块，可以启用或禁用特定的外设时钟。这可以帮助节省功耗并优化系统性能。
> - 复位控制：RCC模块允许开发者对不同外设进行软件复位操作，将外设重置到初始状态。
> - 时钟状态监测：RCC模块提供了一些标志位，可以用于监测系统时钟源和外设时钟的状态。

## 1.7. SDIO（Secure Digital Input Output）
> SDIO（Secure Digital Input Output）是一种接口，用于让SD卡（Secure Digital Card）提供非存储功能，如Wi-Fi、蓝牙、GPS等。SDIO卡是SD卡家族的一部分，除了SD存储卡外，还包括SDIO、SD Combo（结合SD存储和SDIO功能的卡）。
> 以下是一些SDIO的关键点：
> - 非存储应用：SDIO卡是设计用来为那些不需要存储功能的应用提供接口的。例如，你可能会在一些嵌入式设备中找到SDIO Wi-Fi模块或SDIO蓝牙模块。
> - 兼容性：SDIO卡在物理形态和接口上与标准的SD存储卡相似。然而，它们的功能和驱动程序可能完全不同。
> - 扩展性：SDIO为设备提供了一种简单的扩展方法，允许增加如无线通信等功能，而无需修改设备的主硬件。
> - 数据传输速度：与SD卡一样，SDIO卡有不同的速度等级。速度等级影响了数据的传输速率，这对于某些高带宽应用（如视频流）是非常关键的。
> - 驱动支持：虽然SDIO硬件接口可能相对标准化，但具体的卡（如Wi-Fi模块）可能需要特定的驱动支持。
>
> 总的来说，SDIO提供了一种便捷的方式，使得开发者和制造商可以为其设备增加新功能，而无需进行大的硬件改动。不过，选择SDIO模块时需要确保你的主机设备和操作系统支持所选模块的驱动。

## 1.8. 桥接器（Bridges）
> 桥接器（Bridges）在微控制器中常常用来连接不同类型或速度的总线。通过桥接器，一个总线上的设备可以与另一个总线上的设备通信，即使这两个总线的工作方式和速度不同。
> 关于AHB和桥接器之间的关系：
> - 连接不同的AHB总线：在复杂的微控制器设计中，可能存在多个AHB总线。这时，一个AHB到AHB的桥接器可以被用来连接它们。
> - 连接AHB和其他类型的总线：例如，桥接器可以连接AHB和APB（Advanced Peripheral Bus）总线。由于AHB通常用于高性能设备，而APB用于低性能设备，因此桥接器充当了两者之间的通信媒介。
> - 数据宽度转换：桥接器可能还用于转换数据宽度。例如，一个32位AHB总线和一个16位外设总线之间的桥接器可以在两者之间进行适当的数据宽度转换。
> - 性能优化：通过使用桥接器，高性能的AHB总线上的设备可以继续以其最大性能运行，而不受低性能设备的影响。例如，如果一个高速的CPU核心和一个低速的外设都连接到同一个总线上，那么外设可能会拖慢总线，导致CPU性能下降。但是，通过使用桥接器，可以隔离这两个设备，确保它们各自以最大性能运行。
> - 兼容性和模块化：使用桥接器可以简化设计，使得设计更加模块化，并允许在不同的设计中重用相同的模块或子系统。这也为硬件设计提供了更大的灵活性。
>
> 总的来说，桥接器在微控制器设计中起到了重要的角色，允许不同的总线和设备互相通信，并确保整个系统的高效和稳定运行。

## 1.9. CRC（Cyclic Redundancy Check）
> CRC是“Cyclic Redundancy Check”的缩写，是一种常用于检测数据传输或存储的错误的方法。CRC通过对数据序列应用一个确定的算法生成一个简短的固定大小的数值，这个数值通常与数据序列一起传输或存储。接收方可以再次计算CRC值并将其与传输或存储的CRC值进行比较，以确定数据是否已被更改。
> 以下是CRC的一些关键特点：
> - 检测能力：CRC被设计为检测常见的通信错误，如单个位错误、连续位错误等。
> - 简单与高效：CRC计算是一个简单的数学操作，不需要高复杂度的计算。这使得它特别适用于嵌入式系统和实时应用。
> - 多种多样的CRC算法：存在多种CRC算法，每种都有不同的生成多项式。常见的有CRC-16、CRC-32等，它们分别使用16位和32位的生成多项式。
> - 广泛应用：CRC用于多种应用，从简单的串行通信如RS-232到复杂的网络协议如Ethernet。它也被用于文件存储，以检测文件是否已被损坏。
> - 不是用于加密：虽然CRC可以检测数据更改，但它不是一个加密算法，也不能防止故意的数据篡改。
> - 不是100%可靠：虽然CRC是一个强大的错误检测工具，但它不能检测所有的错误。如果数据出现某些特定的错误模式，这些错误可能不会导致CRC值的变化。
>
> 总之，CRC是一个用于检测数据错误的有用工具，它被广泛应用于通信、存储和其他需要数据完整性的领域。

## 1.10. GPIO（General-Purpose Input/Output）
> GPIO 是 "General-Purpose Input/Output"（通用输入/输出）的缩写，这是一种通用的、双向的数字接口，可用于读取数字信号（输入）或发送数字信号（输出）。在微控制器、微处理器、或其他集成电路中，GPIO 引脚通常用于与其他数字电路或模块进行低速、通用的数据交流。

## 1.11. GPIOx_ODR（Output Data Register）
> GPIOx_ODR是“Output Data Register”的缩写。这个寄存器用于设置或获取GPIO的输出值。用于直接设置引脚。

## 1.12. GPIOx_IDR（Input Data Register）
> GPIOx_ODR是“Input Data Register”的缩写。
> GPIOx_IDR允许你读取与GPIO端口相关的引脚的实时输入状态。这对于诸如按钮按下检测、外部传感器状态检测等应用是非常有用的。

## 1.13. GPIOx_CRL（Configuration Register Low）
> CRL 是 "Configuration Register Low" 的缩写。
> CRL负责配置低8个引脚（PIN0到PIN7）

## 1.14. GPIOx_CRH（Configuration Register High）
> CRH 是 "Configuration Register High" 的缩写。
> CRH负责配置高8个引脚（PIN8到PIN15）

## 1.15. GPIOx_BSRR（Bit Set/Reset Register）
> 缩写解释：Bit Set/Reset Register。
> 作用：此寄存器用于原子地设置或重置GPIO端口的引脚。对于STM32的大多数系列，寄存器的前16位用于设置相应引脚（写1将引脚设置为高电平），而后16位用于重置相应引脚（写1将引脚设置为低电平）。这种原子性的操作确保引脚的快速和安全设置/重置，而不涉及读-修改-写的过程。
> 操作此寄存器实际会影响 GPIOx_ODR 寄存器。

## 1.16. GPIOx_BRR（Bit Reset Register）
> 缩写解释：Bit Reset Register。
> 作用：此寄存器用于原子地重置GPIO端口的引脚。它是GPIOx_BSRR的简化版本，仅用于引脚的重置。写1到BRR的相应位会将对应的GPIO引脚重置为低电平。注意：不是所有STM32系列都有这个寄存器，它主要出现在STM32F1的后续系列中。

## 1.17. GPIOx_LCKR（Lock Register）
> 缩写解释：Lock Register。
> 作用：此寄存器用于锁定GPIO端口的配置。一旦锁定了特定的GPIO配置，它不能被修改，除非系统复位。这对于防止某些关键引脚的配置被意外更改是非常有用的。

## 1.18. HSI（High-Speed Internal）
> 在STM32微控制器中，HSI 代表 "High-Speed Internal"（高速内部）振荡器。这是一个内部集成的、相对较高频率的振荡器，通常用作微控制器的时钟源之一。HSI 提供的时钟不如外部振荡器（HSE, High-Speed External）准确，但它有内部集成的优势，即不需要外部组件。
> 一般来说，HSI 是一个不错的时钟源选项，特别是对于不需要极高精度时钟的应用，或者为了减少外部组件而更倾向于使用内部时钟源的情况。由于HSI 是内部集成的，所以它通常更快地启动，这在一些需要快速启动或低功耗的应用中可能是有益的。
> 具体的频率和特性取决于具体的STM32微控制器型号。例如，在一些STM32F1系列的微控制器中，HSI 的频率通常是8MHz。
> 在STM32的设置中，你通常会在RCC（Reset and Clock Control）模块中找到相关的HSI设置选项。通过编程，你可以选择是否使用HSI，以及是否需要将其通过PLL（Phase-Locked Loop）进行倍频等。在一些低功耗模式中，HSI 可以被关闭以节省电能。

## 1.19. 推挽输出（Push-Pull）
> 推挽（Push-Pull）输出是一种常见的数字输出配置方式，在很多微控制器和数字逻辑电路中都可以找到。在推挽输出模式下，一个输出引脚可以被软件配置为高电平（通常是供电电压，如 VCC 或 VDD）或低电平（通常是地，即 GND）。
> 特点：
> - 双向驱动能力：推挽输出可以主动地驱动输出到高电平，也可以主动地拉低到低电平。
> - 强驱动能力：由于能够主动拉高或拉低电平，推挽输出通常具有较强的输出驱动能力。
> - 速度快：通常，推挽输出由于可以主动驱动电平，因此转换速度相对较快。
> - 简单的硬件需求：通常不需要外部的上拉或下拉电阻。
> - 电流方向：电流可以流入或流出该引脚，这取决于设置的电平。在高电平时，电流从 VCC 或 VDD 流出到输出引脚；在低电平时，电流从输出引脚流入 GND。
>
> 常见应用：
> - 点亮或控制LED。
> - 驱动低电流的电机或继电器。
> - 数字信号传输。
> - 与其他数字设备或模块的接口。
>
> 推挽输出是数字电路设计中非常基础和常用的一种输出类型，几乎所有的微控制器都会提供这种配置选项。当你需要一个能主动驱动高或低电平，并具有较强驱动能力的输出时，推挽输出通常是一个好的选择。

## 1.20. 开漏输出（Open-Drain）
> 开漏（Open-Drain）输出是一种在数字电路和微控制器中常见的输出配置方式。在这种模式下，输出引脚可以被主动拉低到地（GND），但不能主动拉高。要让引脚达到高电平状态，通常需要连接一个外部的上拉电阻到某个高电平电源（如 VCC 或 VDD）。
> 特点：
> - 单向驱动能力：在开漏配置中，输出引脚只能被主动拉低到地（GND）。要达到高电平状态，通常需要一个外部的上拉电阻。
> - 无主动高电平驱动：开漏结构不能主动驱动输出到高电平，它依赖于外部上拉电阻或其他电源来实现这一点。
> - 电流方向：在主动拉低时，电流从上拉电阻流入引脚并到GND。
> - 共享数据线：由于其只能主动驱动低电平，多个开漏设备可以共享同一数据线，而不会彼此造成冲突。这使得开漏输出特别适合用于多主机通信。
> - 电平转换：由于开漏或开集结构只关心低电平，它们常被用于电平转换。例如，5V的开漏输出和3.3V的上拉电阻可以一起用于实现5V到3.3V的电平转换。
>
> 常见应用：
> - I2C通信：I2C协议使用开漏或开集器配置来允许多个设备共享同一数据和时钟线。
> - 中断线：多个设备可能使用开漏配置来连接到单个中断线，允许任何设备拉低该线以发出中断信号。
> - 电平转换：用于连接不同操作电压的设备。
>
> 开漏输出提供了一种灵活且有用的输出配置，特别是在需要多个设备共享同一信号线或需要电平转换的应用中。然而，设计时需要注意正确配置上拉电阻，并考虑因上拉电阻可能导致的较慢的信号上升时间。