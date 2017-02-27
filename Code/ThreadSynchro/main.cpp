#include <stdio.h>  
#include <process.h>
#include "MyObject.h"
#include "MyCriticalSection.h"
#include "MyInterLock.h"
#include "MyRWLock.h"
#include "MySemaphore.h"
#include "MyMutex.h"
#include "MyEvent.h"

// �ο����ͣ� http://blog.csdn.net/gengshenghong/article/details/6950068

#define MY_NOSYNCHRO_TEST				// �������߳�ͬ��;

// �û�̬-ͬ����ʽ;
//#define MY_INTERLOCK_TEST				// ԭ�Ӳ���;
//#define MY_CRITICALSECTION_TEST		// �ٽ���;
//#define MY_SRWLOCK_TEST				// ��д��;

// �ں�̬-ͬ����ʽ;
//#define MY_SEMAPHORE_TEST				// �ź���;
//#define MY_MUTEX_TEST					// ������;
//#define MY_EVENT_TEST					// �¼�;

long g_lCount = 0;

#define THREAD_COUNT        10				// �߳���;
#define ACCESS_TIMES        100000			// ���ʹ�������Ĵ�����������ֵ���������ݾ��������Ŀ�����;

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
	_endthread();   // ����ʡ�ԣ����������; 
}

// ���Ժ���;
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

	// �����;
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