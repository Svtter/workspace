#!/usr/bin/python
# coding: utf8

import requests
import os

data = {
    'logintype': '查看详情', # .decode('utf8').encode('gb2312'),
    'loginuser': '201258503107',
    'domainid': '2',
    'password': '124563',
    'refer': '1',
}

# 发送
s = requests.session()
s.headers['User-Agent'] = "Mozilla/5.0 (X11; Linux x86_64; rv:35.0) Gecko/20100101 Firefox/35.0"
result = s.post('http://202.194.168.87/php/user_login.php', data=data)
# result = s.post('http://localhost/html/test.php', data=data)
p = file('temp.htm', 'w')
res = result.content.decode('utf-8').encode('utf-8')
p.write(res)
print(result.content)
