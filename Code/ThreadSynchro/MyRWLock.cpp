#include "MyRWLock.h"

//#define READ_TEST

CMyRWLock::CMyRWLock()
{
	InitializeSRWLock(&m_rwLock);
}

CMyRWLock::~CMyRWLock()
{
}

bool CMyRWLock::Lock()
{
#ifdef READ_TEST
	AcquireSRWLockShared(&m_rwLock);
#else
	AcquireSRWLockExclusive(&m_rwLock);
#endif
	return true;
}

bool CMyRWLock::UnLock()
{
#ifdef READ_TEST
	ReleaseSRWLockShared(&m_rwLock);
#else
	ReleaseSRWLockExclusive(&m_rwLock);
#endif
	return true;
}