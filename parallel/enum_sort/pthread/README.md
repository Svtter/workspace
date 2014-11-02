小注
===

如果使用`pthread_create`不要马上使用`pthread_join`,`join`会使函数马上运行，

并且对数组声明的pthread加锁，造成程序并发执行。
