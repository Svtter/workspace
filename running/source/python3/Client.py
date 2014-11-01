#-*- coding: utf-8 -*-
from socket import *

class TcpClient:
    HOST='127.0.0.1'
    PORT=12345
    BUFSIZ=1024
    ADDR=(HOST, PORT)
    def __init__(self):
        self.client=socket(AF_INET, SOCK_STREAM)
        self.client.connect(self.ADDR)

        while True:
            data=input('>')
            if not data:
                break
            self.client.send(data.encode('utf8'))
            data=self.client.recv(self.BUFSIZ)
            if not data:
                break
            print(data.decode('utf8'))
            
if __name__ == '__main__':
    client=TcpClient()
