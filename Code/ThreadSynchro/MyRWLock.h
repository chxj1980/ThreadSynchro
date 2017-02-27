#pragma once
#include "windows.h"

// ¶ÁÐ´Ëø;
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