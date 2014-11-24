title: 使用gdb调试
date: 2014-11-16 14:42:06
categories:
- ACM
- gdb
tags: 调试
---

最近都是用gcc+vim写代码，昨天突然写个代码算法出个逻辑bug，因为用了大量递归调用，DEB半天出不来也是醉了，于是

学习一下gdb——之前也是勉强使用过，但是明显感觉不爽阿。。所以这次好好学习，记录一下。

目前我能用到的几个命令：

选择调试文件
===

- `<shell>: gdb <file>`
- 或者进入gdb以后，使用

断点
===

显示断点
---
- `(gdb): info break`

添加静态断点
---
- `(gdb): b[reak] + 行数/函数名  (可以用tab补全)`

添加条件断点
---
条件为真，则在断点处停止
- `(gdb): b addr if condition`
    
删除断点
---
删除编号为1的断点, 如果不加参数，会删除所有断点
- `(gdb): delete breakpoint 1`
    
启用/禁用断点
---
- `(gdb): disable breakpoint 1`
- `(gdb): enable breakpoint 1`

运行
===

开始运行
---
- `(gdb):r`
    
继续
---
- `(gdb):c`
    
单步调试
---
不进入单步执行
- `(gdb):n`
进入的单步
- `(gdb):s[tep`


显示变量
===

以变量为var为例

输出var的值
---
- `(gdb):p var`
    
输出上一个求得值
---
- `(gdb):p `
    
输出历史记录中值
---
- `(gdb):p $[num]`
    
输出变量的类型
---
- `(gdb):whatis p`
    
调用函数
---
- `(gdb):p add(a, b)`
    
数组
---
输出a后面的十个元素
- `(gdb):p a@10`

设置运行参数
===

- `(gdb):set args -b -x`
- `(gdb):show args`


参见大牛的部分：(陈皓的gdb讲解)[http://blog.csdn.net/haoel/article/details/2880]

> 二、设置观察点（WatchPoint）

    观察点一般来观察某个表达式（变量也是一种表达式）的值是否有变化了，如果有变化，马上停住程序。我们有下面的几种方法来设置观察点：

    watch <expr>
        为表达式（变量）expr设置一个观察点。一量表达式值有变化时，马上停住程序。

    rwatch <expr>
        当表达式（变量）expr被读时，停住程序。

    awatch <expr>
        当表达式（变量）的值被读或被写时，停住程序。

    info watchpoints
        列出当前所设置了的所有观察点。

TAG
===
- 直接输入`<CR>`，执行上一条命令
