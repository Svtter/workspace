#!/usr/bin/python
# -*- coding:utf-8 -*-

import sys
import socket
import string

# 默认参数
serverHost = '127.0.0.1'
serverPort = 8000
filename = 'hello.html'
# 创建套接字
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 根据命令行给参数赋值
if len(sys.argv) > 1:
    serverHost = sys.argv[1]
    if len(sys.argv) > 2:
        serverPort = string.atoi(sys.argv[2], 10)
        if len(sys.argv) > 3:
            filename = sys.argv[3]
            # 连接服务端
            clientSocket.connect((serverHost, serverPort))
            print "connect to the server..."
            data = 'get /' + filename
            # 向服务端发送数据
            clientSocket.sendall(data)
            print 'send:', data
            # 接收来自服务端的数据并显示
            response = clientSocket.recv(8192)
            print 'received:', response
            # 关闭套接字
            clientSocket.close()
