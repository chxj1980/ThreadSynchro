#include "MyEvent.h"


CMyEvent::CMyEvent()
{
	// 创建事件内核对象;
	m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(m_hEvent);
}

CMyEvent::~CMyEvent()
{
	CloseHandle(m_hEvent);
}

bool CMyEvent::Lock()
{
	WaitForSingleObject(m_hEvent, INFINITE);     // 等待事件;
	ResetEvent(m_hEvent);		// 重置事件，让其他线程继续等待（相当于获取锁）;

	return true;
}

bool CMyEvent::UnLock()
{
	SetEvent(m_hEvent);		// 设置事件，让其他线程可以获取事件（相当于释放锁）;

	return true;
}