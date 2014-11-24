title: "[php]-php的类"
date: 2014-11-12 10:38:59
categories: 
- 脚本语言
- php
tags: class
---

虽然说php是一个。。还是不招骂了吧，不过很多人都说php的类莫名奇妙。。但是由于做作业还是要用的。。。

（本来想顺便学学nodejs的，但是谁有那么多精力啊。。还有js学的像狗屎一样= =）

```php
<?php
class Test
{
    private $name; // 可以定义类的访问权限

    public function __construct($name) //构造函数
    {
        $this->name = $name;
    }
    
    public function echoname
    {
        echo $this->name;
    }
}

a = new Test("This is a.");
$a->echoname();

```

- 构造函数重载我不会，有时间再更新吧。。
- 先记录这些。
