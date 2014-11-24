#!/usr/bin/python
# coding: UTF-8

from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', 8000))

#监听该套接字的连接尝试，５代表允许的最多maxpending个排除的连接尝试
serverSocket.listen(5)
print 'The server socket is ready...'
while True:
    print 'Ready to serve...'
    #接收一个请求并返回一个数据对(s1, (ipaddr,port))
    connectionSocket, addr = serverSocket.accept()
    try:
    # 从套接字接收数据，最多8192字节，返回有接收数据组成的字符串
        message = connectionSocket.recv(8192)
    #取接收到的字符串的第二个单词
        filename = message.split()[1]
    #打开名字为filename(这里是取filename字符串的第二个字符到结尾/filename)的文件
        f=open(filename[1:])
        outputdata = f.readlines(-1)
        for i in range(0, len(outputdata)):
    #发送数据
            connectionSocket.send(outputdata[i])
    #关闭套接字
        connectionSocket.close()
    #错误处理
    except IOError:
        connectionSocket.send('404 Not Found')
        connectionSocket.close()
#关闭server套接字
serverSocket.close()
