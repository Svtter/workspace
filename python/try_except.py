#!/usr/bin/python
# FILENAME: try_except.py

import sys
try:
    s = raw_input('Enter something --> ')
except EOFError:
    print '\nWhy did yo do an EOF on me?'
    sys.exit()
except:
    print 'Some error /Exception occured'
print 'Done'
