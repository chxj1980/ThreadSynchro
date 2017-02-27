#pragma once
#include "windows.h"

// ÁÙ½çÇø;
class CMyCriticalSection
{
public:
	CMyCriticalSection();
	~CMyCriticalSection();

	virtual bool Lock();
	virtual bool UnLock();

private:
	CRITICAL_SECTION m_critSec;
};