#!/usr/bin/env python
# coding: UTF-8

import cPickle as p


# Finish
class item:
    '''项目'''
    def __init__(self, path):
        # error cus no file
        self.path = path
        self.itemlist = []
        if file(self.path) is False:
            f = file(self.path, 'w')
            f.close()
        f = file(self.path)
        self.itemlist = p.load(f)
        f.close()

    def add(self, new_item):
        self.itemlist.append(new_item)

    def show(self):
        print self.itemlist

    def remove(self, rm_item):
        self.itemlist.remove(rm_item)

    def __del__(self):
        f = file(self.path, 'w')
        p.dump(self.itemlist, f)
        f.close()

if __name__ == '__main__':
    a = item('itemlist.data')
    a.show()
