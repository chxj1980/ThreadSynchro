#pragma once
#include "windows.h"

// ��д��;
class CMyRWLock
{
public:
	CMyRWLock();
	~CMyRWLock();

	virtual bool Lock();
	virtual bool UnLock();

private:
	SRWLOCK m_rwLock;
};