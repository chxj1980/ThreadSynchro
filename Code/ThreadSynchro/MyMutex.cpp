#include "MyMutex.h"


CMyMutex::CMyMutex()
{
	m_hMutex = CreateMutex(NULL, FALSE, NULL);       // ���������ں˶���;
}

CMyMutex::~CMyMutex()
{
	CloseHandle(m_hMutex);
}

bool CMyMutex::Lock()
{
	WaitForSingleObject(m_hMutex, INFINITE);     // �ȴ��������;
	return true;
}

bool CMyMutex::UnLock()
{
	ReleaseMutex(m_hMutex);                      // �ͷŻ������;
	return true;
}