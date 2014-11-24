title: Linux系统函数简介
date: 2014-11-21 16:49:54
categories:
- Linux
- 系统函数
tags:
---
本文出自[svtter.com](svtter.com)

系统调用函数说明、参数值及定义

本文摘自老师的资料= =

排版有些糟糕了，有时间再改吧 

1、fork()
---
    创建一个新进程
    int fork()
    其中返回int取值意义如下:
    0:创建子进程,从子进程返回的id值大于0:从父进程返回的子进程id值 -1:创建失败

2、lockf(files,function,size):
---
    用作锁定文件的某些段或者整个文件,本函数适用的头文件为:
    #include<unistd.h>
    参数定义:
    int lockf(files,function,size)
    int files,function;
    long size;
    其中:files是文件描述符:function是锁定和解锁;1表示锁定,0表示解锁。size是锁定和解锁的字节数,若用0,表示从文件的当前位置到文件尾。

3、msgget(key,flag):
---
    获得一个消息的描述符,该描述符指定一个消息队列以便用于其他系统调用。
    该函数使用偷文件如下:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/msg.h>
    参数定义
    int msgget(key,flag)
    `key_tkey;`
    `int flag;`
    语法格式:msgqid=msgget(key,flag)
    其中:msgid是该系统调用返回的描述符,失败则返回-1;flag 本身由操作允许权和控制命令值相或得到。
    如:
    `IP_CREAT|0400` 是否该队列应被创建;
    `IP_EXCL |0400` 是否该队列的创建应是互斥的;等。
4、msgsnd(id,msgp,size,flag):
    发送一消息。
    该函数是用头文件如下:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/msg.h>
    参数定义
    int msgnd(id,msgp,size,flag)
    int id,size,flag;
    struct msgbuf * msgp;
    其中:id是返回消息队列的描述符;msgp是指向用户存储区的一个构造体指针,size指示由msgp
    指向的数据结构中字符数组的长度;即消息的长度。这个数组的最大值由MSG-MAX系统可调用参数来确
    定。flag规定当核心用尽内部缓冲空间时应执行的动作;若在标志flag中末设置IPC_NOWAIT位,则当
    41该消息队列中字节数超过一最大值时,或系统范围的消息数超过某一最大值时,调用msgsnd进程睡眠。
    若是设置IPC_NOWAIT,则在此情况下,msgsnd立即返回。
5、msgrcv(id,msgp,size,type,flag):
    接受一消息。
    该函数调用使用头文件如下:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/msg.h>
    参数定义
    int msgrcv(id,msgp,size,type,flag)
    int id,size,type,flag;
    struct msgbuf * msgq;
    struct sgbuf{long mtpe;chat mtext[];};
    语法格式:
    count=msgrcv(id,msgp,size,type,flag)
    其中:id是用来存放欲接收消息的拥护数据结构的地址;size是msgp中数据数组的大小; type是
    用户要读的消息类型:
    type为0:接收该队列的第一个消息;
    type为正:接收类型type的第一个消息;
    type为负:接收小于或等于type绝对值的最低类型的第一个消息。
    flag规定倘若该队列无消息,核心应当做什么事,如果此时设置了IPC_NOWAIT标志,则立即返回,
    若在flag中设置了MSG_NOERROR,且所接收的消息大小大于size,核心截断所接受的消息。
    count是返回消息正文的字节数。
6、msgctl(id,cmd,buf):
    查询一个消息描述符的状态,设置它的状态及删除一个消息描述符。
    调用该函数使用头文件如下:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/msg.h>
    参数定义
    int msgctl(id,cmd,buf)
    int id,cmd;
    struct msgbuf * msgq;
    struct msqid_ds * buf;
    其中:函数调用成功时返回0,调用不成功时返回-1。id用来识别该消息的描述符;cmd规定命令的
    类型。
    IPC_START将与id相关联的消息队列首标读入buf。
    IPC_SET为这个消息序列设置有效的用户和小组标识及操作允许权和字节的数量。
    IPC_RMID删除id的消息队列。
    buf是含有控制参数或查询结果的用户数据结构的地址。
    附:msgid_ds结构定义如下:
    struct msgid_ds
    {struct ipc_perm msg_perm; /*许可权结构*/
    shot padl[7];
    /*由系统使用*/
    ushort onsg_qnum;
    /*队列上消息数*/
    ushort msg_qbytes;
    /*队列上最大字节数*/
    42ushort msg_lspid;
    /*最后发送消息的PID*/
    ushort msg_lrpid;
    /*最后接收消息的PID*/
    time_t msg__stime;
    /*最后发送消息的时间*/
    time_t msg_rtime;
    /*最后接收消息的时间*/
    me_t msg_ctime;
    /*最后更改时间*/
    };
    struct ipc_perm
    {ushort uid;
    /*当前用户id*/
    ushort gid;
    /*当前进程组id*/
    ushort cuid;
    /*创建用户id*/
    ushort cgid
    /*创建进程组id*/
    ushort mode;
    /*存取许可权*/
    {shot patl;long pad2} /*由系统使用*/
    };
7、shmget(key,size,flag):
    获得一个共享存储区。
    该函数使用头文件如下:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/shm.h>
    语法格式:
    shmid=shmaget(key,size,flag)
    参数定义:
    int shmaget(key,size,flag)
    key_t key;
    int size,flag;
    其中:size是存储区的字节数,key和flag与系统调用msgget中的参数含义相同。
    附:
    操作允许权
    八进制数
    用户可读 00400
            用户可读 00200
                    小组可读 00040
                            小组可读 00020
                                    其他可读 00004
                                            其他可读 00002
    控制命令 值
    IPC_CREAT
    0001000
    IPC_EXCL
    0002000
    如:shmid=shmget(key,size,(IPC_CREAT|0400));
    创建一个关键字为key,长度为size的共享存储区。
8、shmat(id,addr,flag):
    从逻辑上将一个共享存储区附接到进程的虚拟地址空间上。
    该函数调用使用头文件如下:
    #include<sy/types.h>
    43#include<sy/ipc.h>
    #include<sy/msg.h>
    参数定义:
    char * shmat(id,addr,flag)
    int id,flag;
    char * addr;
    语法格式:virtaddr=shmat(id,addr,flag)
    其中:id是共享存储区的标识符,addr是用户要使用共享存储区附接的虚地址,若addr是0,系统
    是否对应用户规定的地址做舍入操作。如果flag中设置了shm_rnd即表示操作系统在必要时舍去这个地
    址。如果设置了shm_rdonly,即表示只允许读操作。viraddr是附接的虚地址。
9、shmdt(addr):
    把一个共享存储区从指定进程的虚地址空间分开。
    调用该函数使用头文件:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/mhm.h>
    参数定义:
    int shmdt(addr)
    char * addr
    其中,当调用成功时,返回0值,调用不成功,返回-1,addr是系统调用shmat所返回的地址。
    10、shmctl(id,cmd,buf):
    对与共享存储区关联的各种参数进行操作,从而对共享存储区进行控制。
    调用该函数使用头文件:
    #include<sy/types.h>
    #include<sy/ipc.h>
    #include<sy/shm.h>
    参数定义:
    int shmctl(id,cmd,buf)
    int id,cmd;
    struct shmid_ds * buf;
    其中:调用成功返回0,否则返回-1。id为被共享存储区的标识符。cmd规定操作的类型。规定如下:
    IPC_STAT:返回包含在指定的shmid相关数据结构中的状态信息,并且把它放置在用户存储区中的*but
    指针所指的数据结构中。执行此命令的进程必须有读取允许权。
    IPC_SET:对于指定的shmid,为它设置有效用户和小组标识和操作存取权。
    IPC_RMID:删除指定的shmid以及与它相关的共享存储区的数据结构。
    SHM_LOCK:在内存中锁定指定的共享存储区,必须是超级用户才可以进行此项操作。
    Buf是一个用户级数据结构地址。
    附:
    shmid_ds
    {struct ipc_perm shm_perm;
    /*允许权结构*/
    int shm_segsz;
    /*段大小*/
    int padl;
    /*由系统使用;*/
    ushort shm_lpid;
    /*最后操作的进程id;*/
    ushort shm_cpid;
    /*创建者的进程id;*/
    ushort shm_nattch;
    /*当前附界数;*/
    44short pad2;
    /*由系统使用;*/
    time_t shm_atime;
    /*最后附接时间*/
    time_t shm_dtime;
    /*最后段接时间*/
    time_t shm_ctime;
    /*最后修改时间*/
    }
11、signal(sig,function):
    允许调用进程控制软中断信号的处理。
    头文件为:
    #include<signal.h>
    参数定义:
    signal(sig,function);
    int sig;
    void(*func)();
    其中:sig的值是:
    SIGHVP 挂起
    SIGINT 键盘按^c键或break键
    键盘按quit键
    SIGQUIT
    SIGILL 非法指令
    SIGIOT IOT指令
    SIGEMT EMT指令
    SIGFPE 浮点运算溢出
    SIGKILL 要求终止进程
    SIGBUS 总线错
    段违例
    SIGSEGV
    SIGSYS 系统调用参数错
    SIGPIPE 向无读者管道上写
    闹钟
    SIGALRM
    软件终结
    SIGTERM
    用户定义信号
    SIGUSRI
    第二个用户定义信号
    SIGUSR2
    SIGCLD 子进程死
    SIGPWR电源故障
    function的解释如下:
    SIG_DEL:缺省操作。对除SIGPWR和SIGCLD外所有信号的缺省操作是进程终结对信号
    SIGQUIT,SIGILL,SIGTRA,SIGIOT,SIGEMT,SIGFPE,SIGBUS,SIGSEGV和SIGSYS它产生一内存映
    像文件。
    SIG_IGN:忽视该信号的出现。
    Function:在该进程中的一个函数地址,在核心返回用户态时,它以软中断信号的序号作为参数调用
    该函数,对除了信号SIGILL,SIGTRAP和SIGTWR以外的信号,核心自动地重新设置软中断信号处理程序
    的值为SIG_DEL,一个进程不能捕获SIGKILL信
