# 1. 编译工具链

- [1. 编译工具链](#1-编译工具链)
  - [1.1. 设置环境变量](#11-设置环境变量)
  - [1.2. armcc、armasm 及 armlink](#12-armccarmasm-及-armlink)
  - [1.3. armar、fromelf 及用户指令](#13-armarfromelf-及用户指令)

## 1.1. 设置环境变量
> 调用这些编译工具，需要用到 Windows 的“命令行提示符工具”，为了让命令行方便地找到这些工具，我们先把工具链的目录添加到系统的环境变量中。

## 1.2. armcc、armasm 及 armlink
> ### 1.2.1. armcc
> armcc 用于把 c/c++ 文件编译成 ARM 指令代码，编译后会输出 ELF 格式的 O 文件 (对象、目标文件)。
>
> 打开 MDK 的 Options for Targe->c/c++ 菜单，可看到 MDK 对编译器的控制命令。
>
> ### 1.2.2. armasm
> armasm 是汇编器，它把汇编文件编译成 O 文件。与 armcc 类似。
>
> MDK 对 armasm 的调用选项可在“Option for Target->Asm”页面进行配置。
>
> ### 1.2.3. armlink
> armlink 是链接器，它把各个 O 文件链接组合在一起生成 ELF 格式的 AXF 文件，AXF 文件是可执行的，下载器把该文件中的指令代码下载到芯片后，该芯片就能运行程序了；利用 armlink 还可以控制程序存储到指定的 ROM 或 RAM 地址。
>
> 在 MDK 中可在“Option for Target->Linker”页面配置 armlink 选项。

## 1.3. armar、fromelf 及用户指令
>
> armar 工具用于把工程打包成库文件，fromelf 可根据 axf 文件生成 hex、bin 文件，hex 和 bin 文件是大多数下载器支持的下载文件格式。
>
> 在 MDK 中，针对 armar 和 fromelf 工具的选项几乎没有，仅集成了生成 HEX 或 Lib 的选项，在 MDK 中可在“Option for Target->Output”页面配置 armar 选项。
>
> 例如如果我们想利用 fromelf 生成 bin 文件，可以在 MDK 的“Option for Target->User”页中添加调用 fromelf 的指令。
>
> 在 User 配置页面中，提供了三种类型的用户指令输入框，在不同组的框输入指令，可控制指令的执行时间，分别是编译前 (Before Compile c/c++ file)、构建前 (Before Build/Rebuild) 及构建后(AfterBuild/Rebuild) 执行。这些指令并没有限制必须是 arm 的编译工具链，例如如果您自己编写了 python 脚本，也可以在这里输入用户指令执行该脚本。