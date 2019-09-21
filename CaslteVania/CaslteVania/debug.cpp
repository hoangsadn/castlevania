#include <Windows.h>
#include "debug.h"
#include <fstream>
#include <iostream>
void DebugOut(wchar_t *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	wchar_t dbg_out[4096];
	vswprintf_s(dbg_out, fmt, argp);
	va_end(argp);
	OutputDebugString(dbg_out);
}


#pragma warning (disable:4996)

//send log to output
#define OUTLOG(s)  \
{                   \
    std::ostringstream os;\
    os << s << endl;\
    OutputDebugStringA(os.str().c_str());   \
}

void printLog(const LPCSTR s, ...)
{
	char buff[1024];
	int length = strlen(s);

	va_list ap;
	va_start(ap, s);
	_vsnprintf(buff, sizeof(buff), s, ap); //sizeof(szBuff)
	va_end(ap);

	OUTLOG(buff);
}