#pragma once
#include "windows.h"

class CMyEvent
{
public:
	CMyEvent();
	~CMyEvent();

	virtual bool Lock();
	virtual bool UnLock();

private:
	HANDLE  m_hEvent;
};