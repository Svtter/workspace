#!/usr/bin/env python
# coding=utf8

import httplib

httpClient = None

try:
    # httpClient = httplib.HTTPConnection('202.194.116.87', 80, timeout=30)
    # httpClient.request('POST', '/php/user_login.php')
    httpClient = httplib.HTTPConnection('localhost', 80, timeout=30)
    httpClient.request('POST', '/html/test.php')
    # response是HTTPResponse对象
    response = httpClient.getresponse()
    print response.status
    print response.reasoncolors
    print response.read()
except Exception, e:
    print e
finally:
    if httpClient:
        httpClient.close()
