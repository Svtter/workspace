title: 从grub rescue修复
date: 2014-11-10 12:15:40
categories:
- Linux
- grub2
tags: grub2
---

修复grub-rescue模式
===

今天删除了一个多余的分区，结果grub找不到原来的启动mod了，也是学习了。

grub-rescue模式中只能用ls, insmod, set root= , set prefix= ,这几个命令。

```

使用ls显示所有的磁盘。

然后ls (hd0, X)/boot/grub2 查看启动的盘符。

set root=(hd0, X);

set prefix=(hd0, X)/boot/grub2

insmod normal

normal

```

发现没搞定，重启还是不幸。

使用`# grub2-install /dev/sda`

然后就搞定= =
