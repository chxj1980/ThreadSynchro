#pragma once
#include "windows.h"

// ԭ�Ӳ���;
class CMyInterLock
{
public:
	CMyInterLock();
	~CMyInterLock();

	static bool Increment(LPLONG lpAddend);		// ����;
	static bool Decrement(LPLONG lpAddend);		// �ݼ�;
};