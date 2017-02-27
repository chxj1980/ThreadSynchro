#pragma once
#include "windows.h"

class CMyMutex
{
public:
	CMyMutex();
	~CMyMutex();

	virtual bool Lock();
	virtual bool UnLock();

private:
	HANDLE  m_hMutex;
};