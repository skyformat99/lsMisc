#pragma warning(disable:4786)
#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include "../tstring.h"

namespace stdwin32 {

	std::string stdGetModuleFileNameA(HINSTANCE hInst=NULL);
	std::wstring stdGetModuleFileNameW(HINSTANCE hInst=NULL);
#ifdef UNICODE
	#define stdGetModuleFileName stdGetModuleFileNameW
#else
	#define stdGetModuleFileName stdGetModuleFileNameA
#endif




	BOOL stdIsFullPath(LPCWSTR pD);
	std::wstring stdCombinePath(LPCWSTR pD1, LPCWSTR pD2);
	std::wstring stdCombinePath(const std::wstring& d1, const std::wstring& d2);
	
	std::wstring stdGetParentDirectory(const std::wstring& path, bool bAddBackslach=false);
	std::wstring stdGetParentDirectory(LPCWSTR pPath, bool bAddBackslach=false);
	
	std::wstring stdGetFileName(const std::wstring& full);
	std::wstring stdGetFileName(LPCWSTR pFull);

	std::vector<std::wstring> stdSplitSCedPath(LPCWSTR pPath);
	



	std::string string_formatA(const std::string fmt, ...);
	std::wstring string_formatW(const std::wstring fmt, ...);
#ifdef UNICODE
	#define string_format string_formatW
#else
	#define string_format string_formatA
#endif



	std::string trimA(const std::string& str,
					 const std::string& whitespace = " \t\r\n");
	std::wstring trimW(const std::wstring& str,
					 const std::wstring& whitespace = L" \t\r\n");
#ifdef UNICODE
	#define trim trimW
#else
	#define trim trimA
#endif



	bool isTdigit(const tstring& str);

	std::wstring stdGetCurrentDirectory();



	bool hasEndingA (std::string const &fullString, std::string const &ending);
	bool hasEndingW (std::wstring const &fullString, std::wstring const &ending);
#ifdef UNICODE
	#define hasEnding hasEndingW
#else
	#define hasEnding hasEndingA
#endif


	bool hasEndingIA (std::string const &fullString, std::string const &ending);
	bool hasEndingIW (std::wstring const &fullString, std::wstring const &ending);
#ifdef UNICODE
	#define hasEndingI hasEndingIW
#else
	#define hasEndingI hasEndingIA
#endif








}

