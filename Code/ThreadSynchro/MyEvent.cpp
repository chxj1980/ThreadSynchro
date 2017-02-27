#include "MyEvent.h"


CMyEvent::CMyEvent()
{
	// �����¼��ں˶���;
	m_hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetEvent(m_hEvent);
}

CMyEvent::~CMyEvent()
{
	CloseHandle(m_hEvent);
}

bool CMyEvent::Lock()
{
	WaitForSingleObject(m_hEvent, INFINITE);     // �ȴ��¼�;
	ResetEvent(m_hEvent);		// �����¼����������̼߳����ȴ����൱�ڻ�ȡ����;

	return true;
}

bool CMyEvent::UnLock()
{
	SetEvent(m_hEvent);		// �����¼����������߳̿��Ի�ȡ�¼����൱���ͷ�����;

	return true;
}