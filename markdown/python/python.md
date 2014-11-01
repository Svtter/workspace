新建pythonstartup文件
===

```python
# python startup file

import readline
import rlcompleter
import atexit
import os

# tab completion
readline.parse_and_bind('tab: complete')

# history file
histfile = os.path.join(os.environ['home'], '.pythonhistory')
try:
    readline.read_history_file(histfile)
except ioerror:
    0
atexit.register(readline.write_history_file, histfile)
del os, histfile, readline, rlcompleter
```

在.profile文件中写入
`export PYTHONSTARTUP=$HOME/.pythonstartupfile`

可以使用py3compile来编译文件，然后使用python3+文件名来运行
