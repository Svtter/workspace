#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

#define READ(a,i) cout << a << i<<" is reading..." << endl;
#define FINR(a,i) cout << a << i<<" finished reading." << endl;
#define WRITE(a,i) cout << a <<i<<" is writing..." << endl;
#define FINW(a, i) cout << a <<i<<" finished writing..." << endl;

void P(mutex &mt)
{
    mt.lock();
}

void V(mutex &mt)
{
    mt.unlock();
}

// 加入unistd.h出现问题，似乎与thread的兼容性比较差，于是重写
void delay()
{
    int sum=0;
    for(int i = 0; i < 10000000; i++)
        sum += i;
}


mutex mr, wsem, rsem, mrc, mwc;
int readcount = 0;
int writecount = 0;

void read(string a)
{
    for(int i = 0; i < 5; i++)
    {
        P(mr);
        P(rsem);
        P(mrc);
        readcount++;
        if(readcount == 1)
            P(wsem);
        V(mrc);
        V(rsem);
        V(mr);
        READ(a, i);
        P(mrc);
        FINR(a, i);
        readcount--;
        if(readcount == 0)
            V(wsem);
        V(mrc);
    }
}

void write(string a)
{
    for(int i = 0; i < 3; i++)
    {
        P(mwc);
        writecount++;
        if(writecount == 1)
            P(rsem);
        V(mwc);
        P(wsem);
        WRITE(a, i);
        FINW(a, i);
        V(wsem);
        P(mwc);
        writecount--;
        if(writecount == 0)
            V(rsem);
        V(mwc);
    }
}

int main()
{
    thread reader1(read, "svtter");
    thread writer1(write, "sr");
    thread writer2(write, "zs");
    thread writer3(write, "yym");

    reader1.join();
    writer1.join();
    writer2.join();
    writer3.join();

    return 0;
}
