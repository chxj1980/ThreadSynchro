#include "MyInterLock.h"

CMyInterLock::CMyInterLock()
{
}


CMyInterLock::~CMyInterLock()
{
}

bool CMyInterLock::Increment(LPLONG lpAddend)
{
	InterlockedIncrement(lpAddend);
	return true;
}

bool CMyInterLock::Decrement(LPLONG lpAddend)
{
	InterlockedDecrement(lpAddend);
	return true;
}