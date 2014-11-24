title: "[Python]-一个Python的备份脚本"
date: 2014-11-14 09:27:29
categories:
- 脚本语言
- Python
tags: backup
---

TAGS
===

- python的注释必须与代码相隔两个空格
- \#与注释语言间必须有一个空格

<!--more-->

```python
#!/usr/bin/python
# FileName: backup.py

import os
import time

# 1. The files and directories be backed up are specified in a list.
source = ['/home/svitter/bin', '/home/svitter/tmp']

# 2. The backup must be stored in a main backup directories.
target_dir = '/home/svitter/backup/'

# 3. The files are backed up into a zipfile
# 4. The name of the zip archieve is the current date and time
target = target_dir + time.strftime('%Y_%m_%d_%H_%M_%S') + '.zip'

# 5. we use the zip command to put the files in a zip archive
zip_command = "zip -qr '%s' %s" % (target, ' '.join(source))

# Run the backup
if os.system(zip_command) == 0:
    print 'Successful backup to', target
else:
    print 'Backup FAILED'
```
