#pragma once

class CMyObject
{
public:
	CMyObject();
	~CMyObject();

	virtual bool Lock();
	virtual bool UnLock();
};