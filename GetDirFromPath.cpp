#include <windows.h>
#include "tstring.h"
#include <malloc.h>
#include <shlwapi.h>
#include <tchar.h>

#include "GetDirFromPath.h"


tstring GetDirFromPath(LPCTSTR pszPathName)
{
	LPTSTR p = (LPTSTR)_alloca( (lstrlen(pszPathName) + 1) * sizeof(TCHAR));
	lstrcpy(p, pszPathName);
	DWORD dwAttributes = ::GetFileAttributes(p);
	if(dwAttributes != 0xFFFFFFFF && (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
	{// this is already dir.
		PathAddBackslash(p);
		return p;
	}

	LPTSTR pSep = _tcsrchr(p, _T('\\'));
	if( pSep==NULL )
	{// illegal path
		return _T("");
	}
	
	*(pSep+1) = 0;
	return p;
}
