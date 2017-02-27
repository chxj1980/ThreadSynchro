#include <stdio.h>  
#include <process.h>
#include "MyObject.h"
#include "MyCriticalSection.h"
#include "MyInterLock.h"
#include "MyRWLock.h"
#include "MySemaphore.h"
#include "MyMutex.h"
#include "MyEvent.h"

// 参考博客： http://blog.csdn.net/gengshenghong/article/details/6950068

#define MY_NOSYNCHRO_TEST				// 不进行线程同步;

// 用户态-同步方式;
//#define MY_INTERLOCK_TEST				// 原子操作;
//#define MY_CRITICALSECTION_TEST		// 临界区;
//#define MY_SRWLOCK_TEST				// 读写锁;

// 内核态-同步方式;
//#define MY_SEMAPHORE_TEST				// 信号量;
//#define MY_MUTEX_TEST					// 互斥量;
//#define MY_EVENT_TEST					// 事件;

long g_lCount = 0;

#define THREAD_COUNT        10				// 线程数;
#define ACCESS_TIMES        100000			// 访问共享变量的次数，增大其值，增加数据竞争发生的可能性;

#ifdef MY_NOSYNCHRO_TEST
	CMyObject g_myLock;
#endif

#ifdef MY_CRITICALSECTION_TEST
	CMyCriticalSection g_myLock;
#endif

#ifdef MY_SRWLOCK_TEST
	CMyRWLock g_myLock;
#endif

#ifdef MY_SEMAPHORE_TEST
	CMySemaphore g_myLock;
#endif

#ifdef MY_MUTEX_TEST
	CMyMutex g_myLock;
#endif

#ifdef MY_EVENT_TEST
	CMyEvent g_myLock;
#endif

void __cdecl ThreadProc(void* para)
{
	printf("sub thread started\n");
	for (int i = 0; i < ACCESS_TIMES; i++)
	{
#ifdef MY_INTERLOCK_TEST
		CMyInterLock::Increment(&g_lCount);
#else
		g_myLock.Lock();
		++g_lCount;
		g_myLock.UnLock();
#endif
	}

	printf("sub thread finished\n");
	_endthread();   // 可以省略，隐含会调用; 
}

// 测试函数;
void Thread_Test()
{
	HANDLE hThread[THREAD_COUNT];
	for (int i = 0; i < THREAD_COUNT; i++)
	{
		hThread[i] = (HANDLE)_beginthread(ThreadProc, 0, NULL);
	}

	for (int i = 0; i < THREAD_COUNT; i++)
	{
		WaitForSingleObject(hThread[i], INFINITE);
	}

	// 检查结果;
	printf("g_lCount: %d\n", g_lCount);
	if (g_lCount == ACCESS_TIMES*THREAD_COUNT)
	{
		printf("Correct Result!\n");
	}
	else
	{
		printf("Error Result!\n");
	}
}

int main()
{
	Thread_Test();

	system("pause");
}