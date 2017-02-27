#pragma once
#include "windows.h"

// 原子操作;
class CMyInterLock
{
public:
	CMyInterLock();
	~CMyInterLock();

	static bool Increment(LPLONG lpAddend);		// 递增;
	static bool Decrement(LPLONG lpAddend);		// 递减;
};