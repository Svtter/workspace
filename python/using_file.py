#!/usr/bin/python
# coding: UTF-8
# FILENAME: using_file.py

poem = '''\
Programming is fun
When the work is done
if you wanna make your work also fun:
    use Python!
'''

f = file('poem.txt.', 'w')  # open for 'writing'
f.write(poem)  # write text to the file
f.close()  # close the file

f = file('poem.txt')
# if no mode is specified read mode is assumed by default
while True:
    line = f.readline()
    if len(line) == 0:  # Zero length indicates EOF
        break
    print line
    # Notice comma ot avoid automatic newline added by Python
f.close()  # close the file
