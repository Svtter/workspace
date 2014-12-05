#!/usr/bin/env python
# coding: UTF-8


import sqlite3

class db:
    '''database'''
    def init(self, db_path):
        self.db_path = db_path
