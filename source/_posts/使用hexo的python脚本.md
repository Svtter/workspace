title: 使用hexo的python脚本
date: 2014-11-19 15:46:23
categories:
- hexo
tags: python
---

为了简化blog的使用写的python脚本，用来简化自己的操作= =

更新了一下。
```python
#!/bin/python
# coding: UTF-8

import sys
import os

# 博客目录
blog_dir = '/home/svitter/svtter.github.io/source/_posts'


def help():
    '''output help information'''
    print '-n: new blog'
    print '-g: Generate and push'
    print '-h: help'

if len(sys.argv) < 2:
    print 'no option'
    help()
else:
    if sys.argv[1].startswith('-'):
        # 改变工作目录
        os.chdir(blog_dir)
        option = sys.argv[1][1:]
        if option == 'n':
            os.system("hexo n " + sys.argv[2])
            os.system("gvim " + sys.argv[2] + ".md")
        elif option == 'g':
            os.system('hexo gm')
            os.system('hexo d')
        elif option == 'h':
            help()
        elif option == 'dir':
            print blog_dir
        else:
            print 'no such command.'
    else:
        help()


```
