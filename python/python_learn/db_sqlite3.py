#!/usr/bin/env python
# coding: UTF-8


'test sqlite3'

import sqlite3


class db:
    '''database'''
    def __init__(self, db_path=None):
        # self.con, self.cursor
        self.conn = sqlite3.connect('test.db')
        self.cursor = self.conn.cursor()
        self.cursor.execute('create table user \
                       (id varchar(20) primary key, name varchar(20))')
        self.cursor.execute('insert into user (id, name) \
                       values (\'1\', \'Michael\')')
        self.cursor.rowcount
        self.db_path = db_path

    def query(self):
        self.cursor.execute('select * from user where id=?', '1')
        values = self.cursor.fetchall()
        print values

    def __del__(self):
        self.cursor.close()
        self.conn.commit()
        self.conn.close()
