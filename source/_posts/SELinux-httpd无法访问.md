title: SELinux-httpd无法访问
date: 2014-11-10 22:17:43
categories:
- Linux
- CentOS
- httpd
tags: httpd
---

目录的问题
===

由于SELinux造成的httpd中的目录无法访问，可以使用

- `chcon -R -t httpd_user_content_t <path to web files>`
- `chcon -R -t httpd_sys_content_t <path to web files>`

mark一个网站()[http://www.jb51.net/os/RedHat/1303.html]

文件夹访问权限
===

以上方法解决了SELinux的问题，但是我的目录依然没有访问权限。

然后看了一下文件的基本属性: ` -rw-r--r--. 1 root root   21 11月 11 12:27 index.html `

应该也是没有问题的。

再查SElinux
===

随后使用`cat /var/log/messages`探索一番，依然没有找到问题所在——SELinux没有报错。

防火墙的问题？不是阿。因为我本身是在内网访问，防火墙应该不会出问题。

那应该是什么问题呢？

配置文件
===

终于在配置文件中找到了问题。

apache在进入2.4.\*以后，不再使用`Allow from all`这种形式了，取而代之，使用`Require from granted`这种格式。晕，就是在此处，`<Directory>`没有设置好，坑了好久阿。。

相对的我这几天一直都在deepin下开发——因为`apt-get`得到的apache之前比较习惯，此外deepin没有se也是省了很多功夫。不过通过这一次，总算是把问题解决了！

鼓励！
