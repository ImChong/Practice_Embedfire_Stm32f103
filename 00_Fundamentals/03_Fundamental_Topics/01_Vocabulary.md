# 1. Vocabulary 词汇表

- [1. Vocabulary 词汇表](#1-vocabulary-词汇表)
  - [1.1. armcc 编译器](#11-armcc-编译器)
  - [1.2. armlink 链接器](#12-armlink-链接器)
  - [1.3. fromelf 格式转换器](#13-fromelf-格式转换器)
  - [1.4. plain binary 二进制文件](#14-plain-binary-二进制文件)
  - [1.5. Interl Hex 十六进制文件](#15-interl-hex-十六进制文件)
  - [1.6. Source Code 源代码](#16-source-code-源代码)
  - [1.7. Object Code 对象代码](#17-object-code-对象代码)
  - [1.8. Image 映像文件](#18-image-映像文件)
  - [1.9. Program Size：Code=xx RO-data=xx RW-data=xx ZI-data=xx](#19-program-sizecodexx-ro-dataxx-rw-dataxx-zi-dataxx)
  - [1.10. 只读存储器（Read-Only Memory，ROM）](#110-只读存储器read-only-memoryrom)

## 1.1. armcc 编译器
> MDK 软件使用的编译器是 armcc 和 armasm。它们根据每个 c/c++ 和汇编源文件编译成对应的以 “.o” 为后缀名的对象文件(Object Code，也称目标文件)，其内容主要是从源文件编译得到的机器码，包含了代码、数据以及调试使用的信息；

## 1.2. armlink 链接器
> 链接器armlink 把各个.o 文件及库文件链接成一个映像文件“.axf”或“.elf”；

## 1.3. fromelf 格式转换器
> 格式转换，一般来说 Windows 或 Linux 系统使用链接器直接生成可执行映像文件 elf 后，内核根据该文件的信息加载后，就可以运行程序了，但在单片机平台上，需要把该文件的内容加载到芯片上，所以还需要对链接器生成的 elf 映像文件利用格式转换器 fromelf 转换成“.bin”或“.hex”文件，交给下载器下载到芯片的 FLASH 或 ROM中。

## 1.4. plain binary 二进制文件


## 1.5. Interl Hex 十六进制文件


## 1.6. Source Code 源代码


## 1.7. Object Code 对象代码


## 1.8. Image 映像文件


## 1.9. Program Size：Code=xx RO-data=xx RW-data=xx ZI-data=xx
> ## 1.9.1. Code
> 机器代码指令
> ## 1.9.2. RO-data
> 常量
> ## 1.9.3. RW-data
> 初值非 0 的全局变量
> ## 1.9.4. ZI-data
> 初值为 0 的全局变量
> ## 1.9.5. ZI-data 栈空间
> 局部变量
> ## 1.9.6. ZI-data 堆空间
> 使用 malloc 动态分配的空间

## 1.10. 只读存储器（Read-Only Memory，ROM）