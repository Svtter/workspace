#!/usr/bin/python
# coding: UTF-8

import urllib
import urllib2
import cookielib

# 模拟登录
cj = cookielib.CookieJar()
# 用户名和密码
post_data = urllib.urlencode({
    'logintype': '查看详情',
    'loginuser': '201258503107',
    'domainid': '2',
    'password': '1',
    'refer': '1',
})

# 登录路径
# path = 'https://202.194.168.87/php/user_login.php'
path = 'http://localhost/html/test.php'
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
opener.addheaders = [('User-agent', 'Opera/9.23')]
urllib2.install_opener(opener)
req = urllib2.Request(path, post_data)
conn = urllib2.urlopen(req)
p = file('tmp.htm', 'w')
res = conn.read().decode('utf-8').encode('utf-8')
p.write(res)

print res
