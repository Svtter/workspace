#!/usr/bin/env python
# coding: UTF-8


'use json item'

__author__ = 'svtter'

import json


class item:
    def __init__(self, path):
        self.path = path
        self.itemlist = {}
        if file(self.path) is False:
            f = file(self.path, 'w')
            f.close()
        f = file(self.path)
        self.itemlist = json.load(f)
        f.close()

    def add(self, new_item):
        pass

    def show(self):
        pass

    def remove(self, rm_item):
        pass

    def __del__(self):
        f = file(self.path, 'w')
        json.dump(self.itemlist, f)
        f.close()

