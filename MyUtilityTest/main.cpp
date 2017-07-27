#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <TlHelp32.h>

#include <string>
#include <vector>

#pragma comment(lib,"Shell32.lib")
// #pragma comment(lib,"comsuppw.lib")
#pragma comment(lib,"Advapi32.lib")



#include "../tstring.h"
#include "../IsFileExists.h"
#include "../ProcessList.h"
#include "../ChangeFilenamable.h"
#include "../PathUtil.h"

#include <stlsoft/smartptr/scoped_handle.hpp>




void testMoveWindowCommon();
void testCommandLine();
void testHira2Kata();
void testGetVersionString();
void testStlMutex();
void testPathUtil();

int main()
{
	testPathUtil();

	testMoveWindowCommon();
	testCommandLine();
	testHira2Kata();
	testGetVersionString();






	// kernel object
	{
		HANDLE h = CreateMutex(NULL, FALSE, NULL);
		if (h == NULL)
			return -1;

		stlsoft::scoped_handle<HANDLE> ko(h, CloseHandle);
	}

	{
		FILE* f = fopen("C:\\T\\Test.txt", "w");
		if (!f)
			return -1;

		stlsoft::scoped_handle<FILE*> fo(f, fclose);
	}

	//TCHAR buf[MAX_PATH];




	std::vector<PROCESSENTRY32> ret;
	GetProcessList(ret);

	TCHAR szT[] = _T("開発機構特別資料");
	tstring t = ChangeFilenamable(szT);

	BOOL b = IsFileExists(_T("c:\\T\\aaa.txt"));
	b = IsFileExistsA("c:\\T\\bbb.txt");
	b = IsFileExistsW(L"c:\\T\\ccc");
	return 0;
}
