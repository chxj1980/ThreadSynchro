#include "windows.h"
#include "MyCriticalSection.h"

CMyCriticalSection::CMyCriticalSection()
{
	::InitializeCriticalSection(&m_critSec);
}

CMyCriticalSection::~CMyCriticalSection()
{
	::DeleteCriticalSection(&m_critSec);
}

bool CMyCriticalSection::Lock()
{
	::EnterCriticalSection(&m_critSec);
	return true;
}

bool CMyCriticalSection::UnLock()
{
	::LeaveCriticalSection(&m_critSec);
	return true;
}