title: python的自动补全
date: 2014-11-21 16:40:38
categories:
- 脚本语言
- Python
tags: [补全, Python]
---

新建python_start_up_file文件
---

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

在`$HOME/.profile`文件中写入
`export PYTHONSTARTUP=$HOME/.python_start_up_file`

小注：
---
可以使用py3compile来编译文件，然后使用python3+文件名来运行
