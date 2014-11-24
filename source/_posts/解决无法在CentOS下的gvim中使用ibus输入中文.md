title: 解决无法在CentOS下的gvim中使用ibus输入中文
date: 2014-11-15 14:54:24
categories:
- Linux
- CentOS
tags: question
---

问题
===

之前在gvim中一直无法使用中文，格外痛苦，后来使用了vim-ibus插件之后，可以在vim中使用中文了，但是依然不能在gvim中使用，一直以为是两个软件冲突的

问题，现在终于解决了。

- gvim version: vim-X11
- ibus version: 1.6

解决方案
===

- 问题出在：使用的vim插件中有插件与ibus冲突，但是奈何找不到X11的log（应该可以找到，找到再说。。）
- 排查方式比较简单，使用`:PluginInstall`,`:PluginClean`即可(考虑到我使用vundle管理插件)
- 去除相应的插件即可(比如现在冲突的是auto-pairs)。如果不想去除冲突插件，可以考虑使用vim-ibus，这个在shell下是可以使得很多冲突减少的。
- 可能auto-pairs在不久的将来就会修复这个bug，请在具体环境下排查
