#pragma once
#include "windows.h"

// �ٽ���;
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