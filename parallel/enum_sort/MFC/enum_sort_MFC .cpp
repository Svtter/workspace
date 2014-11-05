// parallel_mfc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "parallel_mfc.h"
#include "afxwin.h"
#include <afxmt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

#define MAXN 20000
#define MAXV 10000
int a[MAXN+10], b[MAXN+10], at[MAXN+10], bt[MAXN+10];

// 针对ab建立两个随机数数组
void build(int a[], int b[])
{
    srand(time(NULL));
    for(int i = 1; i <= MAXN; i++)
    {
		a[i] = b[i] = rand()%MAXV;
	}
}

//serial enum sort
double serial_enum_sort(int a[], int at[])
{
    double t1, t2;
    t1 = clock();
    int k, i, j;
    for(i = 1; i <= MAXN; i++)
    {
        k = 1;
        for(j = 1; j <= MAXN; j++)
            if(a[i] > a[j] || (a[i] == a[j]) && i > j)
                k++;
        at[k] = a[i];
    }
    t2 = clock();
    return (t2 - t1);
}


// parallel enum sort
int thread_num;
#define NUM_THREADS 4
int count = 0;
CSemaphore se(0, 1);
CSemaphore cc(1, 1);

UINT function(LPVOID pParam)
{
	int k, j;
	int i = (int)pParam;
	//cout << i << "is counting.." << endl;
	for(; i <= MAXN; i += NUM_THREADS)
	{
		k = 1;
		for(j = 1; j <= MAXN; j++)
		{
			if(b[i] > b[j] || (b[i] == b[j] && i > j))
			k++;
		}
		bt[k] = b[i];
	}
	cc.Lock();
	count ++;
	if(count == 4)
		se.Unlock();
	cc.Unlock();
	
	return 0;
}


double parallel_enum_sort(int b[], int bt[])
{
	clock_t t1, t2;
	t1 = clock();
	int i;
	
	for(i = 1; i <= NUM_THREADS; i++)
	{
		AfxBeginThread(function, (LPVOID)i);
	}

	//while(count != 0);
	//WaitForMultipleObjects(sizeof(p), p, TRUE, INFINITE);
	//WaitForSingleObject(hSemaphore, INFINITE);
	se.Lock();
	t2 = clock();
	se.Unlock();
	return (t2 - t1);
}


// 调试数组, len为数组长度
void debug(int a[], int len)
{
    for(int i = 1; i <= len; i++) 
		cout << a[i] << endl;
}


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
			build(a, b);
			memset(bt, 0, sizeof(bt));
			double cost, cost2;

			//serial
			cost = serial_enum_sort(a, at);
			cout << "serial cost is: " << cost << endl;
			//debug(at, 100);

			//parallel
			cost2 = parallel_enum_sort(b, bt);
			cout << "parallel cost is: " << cost2 << endl;
			//debug(bt, 100);

			printf("并行加速比为: %lf\n", cost / cost2);

			system("pause");
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
