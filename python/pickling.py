#!/usr/bin/python
# FILENAME: pickling.py


import cPickle as p

shoplistfile = 'shoplist.data'

shoplist = ['apple', 'mango', 'carrot']

f = file(shoplistfile, 'w')

p.dump(shoplist, f)

f.close()

del shoplist  # remove the shoplist

f = file(shoplistfile)

storedlist = p.load(f)

print storedlist
