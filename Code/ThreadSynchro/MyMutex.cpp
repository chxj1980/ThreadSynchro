#include "MyMutex.h"


CMyMutex::CMyMutex()
{
	m_hMutex = CreateMutex(NULL, FALSE, NULL);       // 创建互斥内核对象;
}

CMyMutex::~CMyMutex()
{
	CloseHandle(m_hMutex);
}

bool CMyMutex::Lock()
{
	WaitForSingleObject(m_hMutex, INFINITE);     // 等待互斥对象;
	return true;
}

bool CMyMutex::UnLock()
{
	ReleaseMutex(m_hMutex);                      // 释放互斥对象;
	return true;
}