#include <stdio.h>

#define NANNR
#define DIRSIZE

typedef struct inode 
{
    struct inode *i_forw;
    struct inode *i_back;
    char l_flag;
    unsigned int i_into; //磁盘i节点编号
    unsigned int i_count; //引用计数
    unsigned short di_number; // 关联文件个数
    unsigned short di_mode; //存取权限
    unsigned short di_uid; // 磁盘i节点用户

    unsigned short di_gid; // 磁盘i节点用户组

    unsigned int di_addr[NADDR]; //物理块号
}inode;

// 目录
typedef struct dinode
{
    unsigned short di_number; //关联文件数
    unsigned short di_mode; //存取权限
    
    unsigned short di_uid;
    unsigned short di_gid;
    unsigned long di_size;
    unsigned int di_addr[NADDR];
}dinode;

typedef struct direct
{
    char d_name[DIRSIZE];//目录名
    unsigned int d_ino; //目录号
}direct;

// superblock
typedef struct filsys
{
    unsigned short s_isize; // i节点块块数
    unsigned long s_fsize;  // 数据块块数

    unsigned int s_nfree;   // 空闲块块数
    unsigned short s_pfree; // 空闲块指针
    unsigned int s_free[NICFREE]; // 空闲块堆栈
    
    unsigned int s_ninode; // 空闲i节点数
    unsigned short s_pinode; // 空闲i节点指针
    unsigned int s_inode[NICINOD]; // 空闲i节点数组

    unsigned int s_rinode; //铭记i节点
    char s_fmod;            //超级块修改标志
}filsys;

// password

typedef struct pwd
{
    unsigned short P_uid;
    unsigned short P_gid;
    char password[PWOSIZ];
}pwd;

typedef struct dir
{
    struct direct direct[DIRNUM];
    int size;
}dir;

typedef struct hinode
{
    struct inode *iforw;
}hinode;

typedef struct file
{
    char f_flag;
    unsigned int f_count;
    struct inode *f_inode;
    unsigned long f_off;
}file;

typedef struct user
{
    unsigned short u_default_mode;
    unsigned short u_uid;
    unsigned short u_gid;
    unsigned short u_ofile[NOFILE];
}user;

void iget();
void iput();
void mkdir();
void namei();
void balloc();
void bfree();
void ialloc();
void ifree();
void iname();
void access();
void _dir();
void chdir();
void open();
void create();
void read();
void write();
void login();
void logout();
void format();
void install();
void close();
void halt();
void delecte();
