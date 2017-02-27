#pragma once
#include "windows.h"

class CMySemaphore
{
public:
	CMySemaphore();
	~CMySemaphore();

	virtual bool Lock();
	virtual bool UnLock();

private:
	HANDLE  m_hObject;
};