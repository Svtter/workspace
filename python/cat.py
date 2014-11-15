#!/usr/bin/python
# coding: UTF-8
# FILENAME: cat.py


import sys


# print sys.argv
# print 'argv array'
# for i in sys.argv:
#     print i
# print sys.argv[1]
# for i in sys.argv[1]:
#     print i


def readfile(filename):
    '''print a file to the Standard output'''
    f = file(filename)
    while True:
        line = f.readline()
        if len(line) == 0:
            break
        print line
    f.close()

if len(sys.argv) < 2:
    print 'no action specified'
    print 'argv:', sys.argv
    sys.exit()

if sys.argv[1].startswith('--'):  # 利用startwith
    option = sys.argv[1][2:]
    # print option
    if option == 'version':
        print 'Version 1.2'
    elif option == 'help':
        print '''\
This program printsfiles to the Standard output.
Any number of files can be specified.
Options include：
    --version : Prints the version number
    --help : Display this help'''
    else:
        print 'Unknow option'
    sys.exit()
else:
    for filename in sys.argv[1:]:
        readfile(filename)
