#include "MySemaphore.h"


CMySemaphore::CMySemaphore()
{
	// 创建信号量，初始计数为0，最大计数为1;
	m_hObject = CreateSemaphore(NULL, 0, 1, NULL);        
	// 将计数设置为1
	ReleaseSemaphore(m_hObject, 1, NULL);
}

CMySemaphore::~CMySemaphore()
{
	CloseHandle(m_hObject);
}

bool CMySemaphore::Lock()
{
	// 获取信号量后 计数会减1;
	WaitForSingleObject(m_hObject, INFINITE);

	return true;
}

bool CMySemaphore::UnLock()
{
	// 信号量加1;
	ReleaseSemaphore(m_hObject, 1, NULL);

	return true;
}