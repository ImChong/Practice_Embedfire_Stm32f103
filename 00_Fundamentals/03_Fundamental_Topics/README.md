# 1. MDK 的编译过程及文件类型全解
此文件夹内为 MDK 的编译过程及文件类型全解

- [1. MDK 的编译过程及文件类型全解](#1-mdk-的编译过程及文件类型全解)
  - [1.1. Vocabulary 词汇表](#11-vocabulary-词汇表)
    - [1.1.1. armcc 编译器](#111-armcc-编译器)
    - [1.1.2. armlink 链接器](#112-armlink-链接器)
    - [1.1.3. fromelf 格式转换器](#113-fromelf-格式转换器)
    - [1.1.4. plain binary 二进制文件](#114-plain-binary-二进制文件)
    - [1.1.5. Interl Hex 十六进制文件](#115-interl-hex-十六进制文件)
    - [1.1.6. Source Code 源代码](#116-source-code-源代码)
    - [1.1.7. Object Code 对象代码](#117-object-code-对象代码)
    - [1.1.8. Image 映像文件](#118-image-映像文件)

## 1.1. Vocabulary 词汇表

### 1.1.1. armcc 编译器
MDK 软件使用的编译器是 armcc 和 armasm。它们根据每个c/c++ 和汇编源文件编译成对应的以“.o”为后缀名的对象文件(Object Code，也称目标文件)，其内容主要是从源文件编译得到的机器码，包含了代码、数据以及调试使用的信息；

### 1.1.2. armlink 链接器

### 1.1.3. fromelf 格式转换器

### 1.1.4. plain binary 二进制文件

### 1.1.5. Interl Hex 十六进制文件

### 1.1.6. Source Code 源代码

### 1.1.7. Object Code 对象代码

### 1.1.8. Image 映像文件