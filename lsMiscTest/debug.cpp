#include "debug.h"

void mytrace(LPCWSTR p)
{
	OutputDebugString(p);
	OutputDebugString(L"\r\n");
}
void mytrace(const std::wstring& ss)
{
	OutputDebugString(ss.c_str());
	OutputDebugString(L"\r\n");
}