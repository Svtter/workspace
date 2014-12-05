#!/usr/bin/env python
# coding: UTF-8

from Tkinter import *


class Application(Frame):
    def __init__(self):
        Frame.__init__(self)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.helloLabel = Label(self, text='Hello, world!')
        self.helloLabel.pack()
        self.quitButton = Button(self, text='Quit', command=self.quit)
        self.quitButton.pack()

if __name__ == '__main__':
    app = Application()
    # 窗口标题:
    app.master.title('Hello World')
    # 主消息循环:
    app.mainloop()
