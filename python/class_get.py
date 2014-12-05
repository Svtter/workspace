#!/usr/bin/env python
# coding: UTF-8


class Animal(object):
    def run(self):
        print 'Animal run...'

class Dog(Animal):
    pass

class Cat(Animal):
    pass

dog = Dog()
cat = Cat()

dog.run()
cat.run()
