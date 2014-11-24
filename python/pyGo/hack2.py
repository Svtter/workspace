#!/usr/bin/python
# coding: utf-8

import requests

up = raw_input('输入上界: ')
down = raw_input('输入下界: ')

for i in range(up, down):
    loginuser = i
    passwd = i
    data = {
        'logintype': '查看详情',
        'loginuser': loginuser,
        'domainid': '1',
        'password': passwd,
        'refer': '1',
    }

    # 发送
    s = requests.session()
    result = s.post('http://localhost/html/test.php', data=data)

    print(result.text)
