- [1. 嵌入式基础知识相关](#1-嵌入式基础知识相关)
  - [1.1. 数据手册（Data Sheet）](#11-数据手册data-sheet)
  - [1.2. 参考手册（Reference Manual）](#12-参考手册reference-manual)
  - [1.3. ISP（In-System Programming）](#13-ispin-system-programming)
  - [1.4. NRST（Negative Reset）](#14-nrstnegative-reset)
  - [1.5. RST（Reset）](#15-rstreset)
  - [1.6. RTS（Request to Send）](#16-rtsrequest-to-send)
  - [1.7. DTR（Data Terminal Ready）](#17-dtrdata-terminal-ready)
  - [1.8. SWD（Serial Wire Debug）](#18-swdserial-wire-debug)
  - [1.9. 内部 FLASH](#19-内部-flash)
  - [1.10. 系统存储器（System Memory）](#110-系统存储器system-memory)
  - [1.11. 内部 SRAM（Static Random Access Memory）](#111-内部-sramstatic-random-access-memory)
  - [1.12. CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）](#112-cmsis-dapcortex-microcontroller-software-interface-standard---debug-access-port)
- [2. 寄存器相关](#2-寄存器相关)
  - [2.1. 寄存器（Register）](#21-寄存器register)
  - [2.2. FSMC（Flexible static memory controller）](#22-fsmcflexible-static-memory-controller)
  - [2.3. DMA（Direct Memory Access）](#23-dmadirect-memory-access)
  - [2.4. AHB（Advanced High-performance Bus）](#24-ahbadvanced-high-performance-bus)
  - [2.5. APB（Advanced Peripheral Bus）](#25-apbadvanced-peripheral-bus)
  - [2.6. RCC（Reset and Clock Control）](#26-rccreset-and-clock-control)
  - [2.7. SDIO（Secure Digital Input Output）](#27-sdiosecure-digital-input-output)
  - [2.8. 桥接器（Bridges）](#28-桥接器bridges)
  - [2.9. CRC（Cyclic Redundancy Check）](#29-crccyclic-redundancy-check)
  - [2.10. GPIO（General-Purpose Input/Output）](#210-gpiogeneral-purpose-inputoutput)
  - [2.11. GPIOx\_ODR（Output Data Register）](#211-gpiox_odroutput-data-register)
  - [2.12. GPIOx\_IDR（Input Data Register）](#212-gpiox_idrinput-data-register)
  - [2.13. GPIOx\_CRL（Configuration Register Low）](#213-gpiox_crlconfiguration-register-low)
  - [2.14. GPIOx\_CRH（Configuration Register High）](#214-gpiox_crhconfiguration-register-high)
  - [2.15. GPIOx\_BSRR（Bit Set/Reset Register）](#215-gpiox_bsrrbit-setreset-register)
  - [2.16. GPIOx\_BRR（Bit Reset Register）](#216-gpiox_brrbit-reset-register)
  - [2.17. GPIOx\_LCKR（Lock Register）](#217-gpiox_lckrlock-register)
  - [2.18. HSI（High-Speed Internal）](#218-hsihigh-speed-internal)
  - [2.19. 推挽输出（Push-Pull）](#219-推挽输出push-pull)
  - [2.20. 开漏输出（Open-Drain）](#220-开漏输出open-drain)
- [3. 文件类型相关](#3-文件类型相关)
  - [3.1. .sct 文件](#31-sct-文件)
  - [3.2. .uvprojx 文件](#32-uvprojx-文件)
  - [3.3. .uvoptx 文件](#33-uvoptx-文件)
  - [3.4. .uvguix. 文件](#34-uvguix-文件)

## 1. 嵌入式基础知识相关

### 1.1. 数据手册（Data Sheet）
> 基础规格：数据手册主要提供微控制器的基础规格，例如工作电压、频率范围、尺寸、引脚配置等。
> 硬件概述：数据手册通常会概述微控制器的硬件结构，包括各种外设、内存大小和种类。
> 引脚信息：具体的引脚分配、电气特性（如输入电压、输出电流等）。
> 电气参数：各种电气特性，包括最大/最小电压、电流、功耗等。
> 简单应用案例：可能会包括一些基础的应用电路图。
> 订购信息：不同型号和包装形式的订购代码。
> 数据手册通常更短，更侧重于硬件和电气参数。

### 1.2. 参考手册（Reference Manual）
> 外设详解：参考手册提供了详细的信息关于微控制器内部的各种外设（如GPIO、USART、ADC等）的工作原理。
> 寄存器映射：详细列出各种外设的寄存器映射和位定义。
> 功能描述：对各个功能模块（例如，电源管理、时钟系统等）有深入的描述。
> 编程指导：包括一些编程的实例和流程，以及与硬件交互时需要注意的事项。
> 系统配置：如何配置微控制器的各种硬件和软件选项。
> 参考手册通常更长，更详细，更侧重于软件开发和硬件配置。
> 简而言之，如果你想了解微控制器的电气特性和基础规格，你应该查阅数据手册。如果你正在进行编程和开发工作，那么参考手册会是一个更有用的资源。在实际开发过程中，这两种文档通常都是必要的。

### 1.3. ISP（In-System Programming）
> ISP（In-System Programming）是一种通过连接到目标设备的外部接口，在设备内部编程或修改程序代码和数据的技术。这种技术通常用于更新固件、修改配置、烧录Bootloader等操作，而无需将芯片从电路板上取下来，使得在生产和维护阶段都能更加便捷地进行。

### 1.4. NRST（Negative Reset）
> NRST 通常代表 "nRST"，其中 "n" 代表 "not"，意思是反相。它在电子和嵌入式系统领域中常用来表示 "Negative Reset"，即负向复位信号。这个信号用于将一个设备或电路恢复到初始状态，通常是通过将设备的内部状态清零或将其重新启动来实现。

### 1.5. RST（Reset）
> "RST" 通常是 "Reset"（复位）的缩写。它表示一种操作或信号，用于将设备、系统或电路恢复到初始状态，以便进行初始化或排除故障。复位操作通常会清除设备的内部状态，将其返回到一个可控的状态，以便重新启动或重新配置。

### 1.6. RTS（Request to Send）
> "RTS" 通常是 "Request to Send" 的缩写，它是一种用于串行通信的信号，用于控制数据的发送。在串行通信中，数据的发送和接收需要一定的协调，以确保数据能够正确地传输。

### 1.7. DTR（Data Terminal Ready）
> "DTR" 通常是 "Data Terminal Ready" 的缩写，它是一种用于串行通信的信号，用于指示数据终端设备（通常是计算机或控制器）是否已准备好进行通信。"DTR" 信号与串行通信中的数据流控制和设备连接状态有关。

### 1.8. SWD（Serial Wire Debug）
> SWD（Serial Wire Debug）是一种用于嵌入式系统调试和编程的接口协议，其简单的硬件连接和高效的数据传输使其成为了嵌入式开发中常用的调试工具接口。

### 1.9. 内部 FLASH
> 内部闪存（Flash）是一种非易失性存储器，通常用于存储程序代码和常量数据。它具有以下特点：
> - 非易失性：Flash 存储器在断电情况下可以保留存储的数据，适用于存储长期不变的程序代码。
> - 可擦写和可编程：Flash 存储器可以通过特定的操作擦除并重新编程，允许更新固件或程序。
> - 相对较大容量：Flash 存储器通常具有较大的容量，足以存储整个操作系统和应用程序代码。
> - 擦写次数有限：每个 Flash 存储单元的擦写次数是有限的，需要谨慎设计以避免过度使用。

### 1.10. 系统存储器（System Memory）
> 系统存储器通常指的是存储启动引导程序、系统配置数据、引导加载程序等重要信息的存储区域。这个区域可以是内部闪存的一部分，也可以是专门的存储芯片。它具有以下特点：
> - 存储重要数据：系统存储器通常用于存储启动引导程序、配置信息等，以确保系统在启动时能够正常工作。
> - 可靠性要求高：系统存储器中的数据需要高可靠性，因为它们与系统启动和操作相关。

### 1.11. 内部 SRAM（Static Random Access Memory）
> SRAM（Static Random Access Memory，静态随机存取存储器）是一种类型的计算机存储器，用于临时存储数据和变量。与动态随机存取存储器（DRAM）相比，SRAM具有更快的读写速度和较低的访问延迟，但通常也更昂贵且需要更多的电力。
> 内部静态随机存储器（SRAM）是一种用于存储临时数据和变量的存储器，它具有以下特点：
> - 高速读写：SRAM 存储器的读写速度很快，适用于临时存储数据和变量。
> - 临时性：SRAM 存储器中的数据在断电后会丢失，适用于存储程序执行期间的中间结果和变量。
> - 相对较小容量：SRAM 存储器通常比 Flash 存储器小，因此主要用于存储短期数据。

### 1.12. CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）
> CMSIS-DAP（Cortex Microcontroller Software Interface Standard - Debug Access Port）是一种用于嵌入式系统调试的标准接口协议。它是由ARM（现在的ARM Limited）提出并定义的，旨在提供一种通用的调试和编程接口，以便开发者可以使用统一的方式对不同的Cortex-M微控制器进行调试和编程操作。
> CMSIS-DAP通常用于创建支持JTAG和SWD（Serial Wire Debug）等调试接口的工具，如调试器、编程器和仿真器。通过CMSIS-DAP，开发者可以实现以下功能：
> - 调试操作：允许开发者在目标微控制器上运行、暂停、单步执行、查看寄存器和内存等操作，以进行代码调试和故障排除。
> - 程序烧录：可以通过CMSIS-DAP接口将编译后的固件程序加载到目标微控制器的内部Flash中。
> - 芯片复位：支持对目标微控制器进行软件复位或硬件复位操作。
> - 性能分析：一些CMSIS-DAP实现还支持性能分析功能，如跟踪和性能计数器。
> - 通用性：CMSIS-DAP标准化了接口协议，使得兼容不同厂家和型号的Cortex-M微控制器变得更加容易。

## 2. 寄存器相关

### 2.1. 寄存器（Register）
> 在计算机体系结构和嵌入式系统中，寄存器是一种小型的、高速的临时存储器组件，用于存储和处理计算机程序和数据。寄存器通常直接集成在中央处理器（CPU）内部，用于执行指令和进行运算。

### 2.2. FSMC（Flexible static memory controller）
> FSMC 的英文全称是 Flexible static memory controller，叫灵活的静态的存储器控制器，是STM32F10xx 中一个很有特色的外设，通过FSMC，我们可以扩展内存，如外部的SRAM，NAND-FLASH 和NORFLASH。但有一点我们要注意的是，FSMC 只能扩展静态的内存，即名称里面的S：static，不能是动态的内存，比如SDRAM 就不能扩展。

### 2.3. DMA（Direct Memory Access）
> DMA（Direct Memory Access，直接内存访问）是一种计算机和嵌入式系统中用于高速数据传输的技术。它允许外部设备或内部模块直接访问系统内存，而无需CPU的直接干预。这种方式可以显著提高数据传输速度，减轻CPU的负担，同时提高系统性能。

### 2.4. AHB（Advanced High-performance Bus）
> AHB（Advanced High-performance Bus，高级高性能总线）。AHB是一种高性能总线协议，通常用于连接高性能组件，如处理器核心、高速缓存和其他高带宽要求的组件。AHB总线使用分级的“主从”体系结构，支持高性能传输和多主设备。

### 2.5. APB（Advanced Peripheral Bus）
> APB（Advanced Peripheral Bus）。APB是一种较低性能、较低速度的总线，主要用于连接外围设备。它适用于不需要高速数据传输的外设，如定时器、GPIO（通用输入/输出口）、串口等。APB总线可以分为APB1和APB2两个子总线。
> ##### APB1（Advanced Peripheral Bus 1）
> - 速度和性能：APB1总线的速度相对较低，通常用于连接一些低速外设。
> - 外设连接：APB1总线连接了一些相对不需要高速访问的外设，如低速串口、定时器、看门狗定时器等。
> - 分频器：APB1总线的时钟源可以使用分频器进行分频，以获取所需的时钟频率。
> ##### APB2（Advanced Peripheral Bus 2）
> - 速度和性能：APB2总线的速度相对较高，适用于连接一些需要更高性能的外设。
> - 外设连接：APB2总线连接了一些需要较高性能访问的外设，如高速串口、USB等。
> - 分频器：APB2总线的时钟源可以使用分频器进行分频，以获取所需的时钟频率。

### 2.6. RCC（Reset and Clock Control）
> RCC代表的是Reset and Clock Control，即复位与时钟控制模块。它是用于配置和控制微控制器内部时钟源和外设的重要模块。通过RCC模块，开发者可以管理微控制器的时钟设置，以满足不同应用的需求。
> RCC模块的主要功能包括：
> - 时钟源选择：RCC模块允许开发者选择不同的时钟源，如内部振荡器、外部晶振、PLL（Phase-Locked Loop）等。这些时钟源可以用于驱动不同的系统组件和外设。
> - 时钟分频：RCC模块允许开发者对时钟进行分频，以获取所需的时钟频率。分频可以用于降低时钟频率以节省功耗，或者将时钟频率提高以满足高性能要求。
> - 时钟使能和失能：通过RCC模块，可以启用或禁用特定的外设时钟。这可以帮助节省功耗并优化系统性能。
> - 复位控制：RCC模块允许开发者对不同外设进行软件复位操作，将外设重置到初始状态。
> - 时钟状态监测：RCC模块提供了一些标志位，可以用于监测系统时钟源和外设时钟的状态。

### 2.7. SDIO（Secure Digital Input Output）
> SDIO（Secure Digital Input Output）是一种接口，用于让SD卡（Secure Digital Card）提供非存储功能，如Wi-Fi、蓝牙、GPS等。SDIO卡是SD卡家族的一部分，除了SD存储卡外，还包括SDIO、SD Combo（结合SD存储和SDIO功能的卡）。
> 以下是一些SDIO的关键点：
> - 非存储应用：SDIO卡是设计用来为那些不需要存储功能的应用提供接口的。例如，你可能会在一些嵌入式设备中找到SDIO Wi-Fi模块或SDIO蓝牙模块。
> - 兼容性：SDIO卡在物理形态和接口上与标准的SD存储卡相似。然而，它们的功能和驱动程序可能完全不同。
> - 扩展性：SDIO为设备提供了一种简单的扩展方法，允许增加如无线通信等功能，而无需修改设备的主硬件。
> - 数据传输速度：与SD卡一样，SDIO卡有不同的速度等级。速度等级影响了数据的传输速率，这对于某些高带宽应用（如视频流）是非常关键的。
> - 驱动支持：虽然SDIO硬件接口可能相对标准化，但具体的卡（如Wi-Fi模块）可能需要特定的驱动支持。
>
> 总的来说，SDIO提供了一种便捷的方式，使得开发者和制造商可以为其设备增加新功能，而无需进行大的硬件改动。不过，选择SDIO模块时需要确保你的主机设备和操作系统支持所选模块的驱动。

### 2.8. 桥接器（Bridges）
> 桥接器（Bridges）在微控制器中常常用来连接不同类型或速度的总线。通过桥接器，一个总线上的设备可以与另一个总线上的设备通信，即使这两个总线的工作方式和速度不同。
> 关于AHB和桥接器之间的关系：
> - 连接不同的AHB总线：在复杂的微控制器设计中，可能存在多个AHB总线。这时，一个AHB到AHB的桥接器可以被用来连接它们。
> - 连接AHB和其他类型的总线：例如，桥接器可以连接AHB和APB（Advanced Peripheral Bus）总线。由于AHB通常用于高性能设备，而APB用于低性能设备，因此桥接器充当了两者之间的通信媒介。
> - 数据宽度转换：桥接器可能还用于转换数据宽度。例如，一个32位AHB总线和一个16位外设总线之间的桥接器可以在两者之间进行适当的数据宽度转换。
> - 性能优化：通过使用桥接器，高性能的AHB总线上的设备可以继续以其最大性能运行，而不受低性能设备的影响。例如，如果一个高速的CPU核心和一个低速的外设都连接到同一个总线上，那么外设可能会拖慢总线，导致CPU性能下降。但是，通过使用桥接器，可以隔离这两个设备，确保它们各自以最大性能运行。
> - 兼容性和模块化：使用桥接器可以简化设计，使得设计更加模块化，并允许在不同的设计中重用相同的模块或子系统。这也为硬件设计提供了更大的灵活性。
>
> 总的来说，桥接器在微控制器设计中起到了重要的角色，允许不同的总线和设备互相通信，并确保整个系统的高效和稳定运行。

### 2.9. CRC（Cyclic Redundancy Check）
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

### 2.10. GPIO（General-Purpose Input/Output）
> GPIO 是 "General-Purpose Input/Output"（通用输入/输出）的缩写，这是一种通用的、双向的数字接口，可用于读取数字信号（输入）或发送数字信号（输出）。在微控制器、微处理器、或其他集成电路中，GPIO 引脚通常用于与其他数字电路或模块进行低速、通用的数据交流。

### 2.11. GPIOx_ODR（Output Data Register）
> GPIOx_ODR是“Output Data Register”的缩写。这个寄存器用于设置或获取GPIO的输出值。用于直接设置引脚。

### 2.12. GPIOx_IDR（Input Data Register）
> GPIOx_ODR是“Input Data Register”的缩写。
> GPIOx_IDR允许你读取与GPIO端口相关的引脚的实时输入状态。这对于诸如按钮按下检测、外部传感器状态检测等应用是非常有用的。

### 2.13. GPIOx_CRL（Configuration Register Low）
> CRL 是 "Configuration Register Low" 的缩写。
> CRL负责配置低8个引脚（PIN0到PIN7）

### 2.14. GPIOx_CRH（Configuration Register High）
> CRH 是 "Configuration Register High" 的缩写。
> CRH负责配置高8个引脚（PIN8到PIN15）

### 2.15. GPIOx_BSRR（Bit Set/Reset Register）
> 缩写解释：Bit Set/Reset Register。
> 作用：此寄存器用于原子地设置或重置GPIO端口的引脚。对于STM32的大多数系列，寄存器的前16位用于设置相应引脚（写1将引脚设置为高电平），而后16位用于重置相应引脚（写1将引脚设置为低电平）。这种原子性的操作确保引脚的快速和安全设置/重置，而不涉及读-修改-写的过程。
> 操作此寄存器实际会影响 GPIOx_ODR 寄存器。

### 2.16. GPIOx_BRR（Bit Reset Register）
> 缩写解释：Bit Reset Register。
> 作用：此寄存器用于原子地重置GPIO端口的引脚。它是GPIOx_BSRR的简化版本，仅用于引脚的重置。写1到BRR的相应位会将对应的GPIO引脚重置为低电平。注意：不是所有STM32系列都有这个寄存器，它主要出现在STM32F1的后续系列中。

### 2.17. GPIOx_LCKR（Lock Register）
> 缩写解释：Lock Register。
> 作用：此寄存器用于锁定GPIO端口的配置。一旦锁定了特定的GPIO配置，它不能被修改，除非系统复位。这对于防止某些关键引脚的配置被意外更改是非常有用的。

### 2.18. HSI（High-Speed Internal）
> 在STM32微控制器中，HSI 代表 "High-Speed Internal"（高速内部）振荡器。这是一个内部集成的、相对较高频率的振荡器，通常用作微控制器的时钟源之一。HSI 提供的时钟不如外部振荡器（HSE, High-Speed External）准确，但它有内部集成的优势，即不需要外部组件。
> 一般来说，HSI 是一个不错的时钟源选项，特别是对于不需要极高精度时钟的应用，或者为了减少外部组件而更倾向于使用内部时钟源的情况。由于HSI 是内部集成的，所以它通常更快地启动，这在一些需要快速启动或低功耗的应用中可能是有益的。
> 具体的频率和特性取决于具体的STM32微控制器型号。例如，在一些STM32F1系列的微控制器中，HSI 的频率通常是8MHz。
> 在STM32的设置中，你通常会在RCC（Reset and Clock Control）模块中找到相关的HSI设置选项。通过编程，你可以选择是否使用HSI，以及是否需要将其通过PLL（Phase-Locked Loop）进行倍频等。在一些低功耗模式中，HSI 可以被关闭以节省电能。

### 2.19. 推挽输出（Push-Pull）
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

### 2.20. 开漏输出（Open-Drain）
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

## 3. 文件类型相关

### 3.1. .sct 文件
> 在 Keil 环境中，.sct 文件是一个用于描述程序如何在目标硬件的内存中布局的链接脚本文件（Scatter-Load Description File）。这个文件用于定义哪些代码和数据段应该放在哪个内存区域（例如 RAM, FLASH 等）。它的主要目的是为了在编译和链接过程中进行内存分配。

### 3.2. .uvprojx 文件
> 这是 Keil µVision 项目文件，它包含了项目的核心配置信息。这包括目标硬件、编译器选项、链接器选项、包含的源文件等。通常，这个文件会在你创建一个新项目时自动生成。

### 3.3. .uvoptx 文件
> 这个文件是与项目相关的设置和选项的存储位置，但主要是那些不直接影响编译和构建过程的设置。这通常包括调试设置、断点信息和其他用户自定义设置。这些信息通常是特定于开发者的，因此 .uvoptx 文件通常不会与源代码一起进行版本控制。

### 3.4. .uvguix. 文件
> 这个文件包含了 Keil µVision GUI（图形用户界面）的布局和设置信息。这可能包括窗口大小、位置，以及其他个性化的界面设置。这些设置通常是特定于开发者的，因此一般也不会与源代码一起进行版本控制。