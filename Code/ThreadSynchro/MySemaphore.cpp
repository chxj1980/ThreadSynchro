#include "MySemaphore.h"


CMySemaphore::CMySemaphore()
{
	// �����ź�������ʼ����Ϊ0��������Ϊ1;
	m_hObject = CreateSemaphore(NULL, 0, 1, NULL);        
	// ����������Ϊ1
	ReleaseSemaphore(m_hObject, 1, NULL);
}

CMySemaphore::~CMySemaphore()
{
	CloseHandle(m_hObject);
}

bool CMySemaphore::Lock()
{
	// ��ȡ�ź����� �������1;
	WaitForSingleObject(m_hObject, INFINITE);

	return true;
}

bool CMySemaphore::UnLock()
{
	// �ź�����1;
	ReleaseSemaphore(m_hObject, 1, NULL);

	return true;
}