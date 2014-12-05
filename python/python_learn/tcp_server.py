#!/usr/bin/env python2
# coding: UTF-8

import socket
import threading
import time


def tcplink(sock, addr):
    print('Accept new connection from %s:%s...' % addr)
    sock.send('Welcome!')
    while True:
        data = sock.recv(1024)
        time.sleep(1)
        if data == 'exit' or not data:
            break
        sock.send('Hello, %s!' % data)
    sock.close()
    print("Connection from %s:%s closed" % addr)

# build a socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(('127.0.0.1', 9999))
# max 5 connect
s.listen(5)
print('Waiting for connection ...')

while True:
    sock, addr = s.accept()
    t = threading.Thread(target=tcplink, args=(sock, addr))
    t.start()
