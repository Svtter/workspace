#!/usr/bin/python
# coding: UTF-8

import socket
import sys

port = 70
host = sys.argv[1]
filename = sys.argv[2]

s = socket.socket(socket.AP_INET, socket.SOCK_STREAM)
s.connect((host, port))

s.sendall(filename + '\r\n')

while 1:
    buf = s.recv(2048)
    if not len(buf):
        break
    sys.stdout.write(buf)
