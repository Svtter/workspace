#!/usr/bin/python
# FILENAME: class_init.py


class Person:
    def __init__(self):
        self.name = 'svtter'

    def sayHi(self):
        print 'Hello, my name is:', self.name

p = Person()
p.sayHi()
