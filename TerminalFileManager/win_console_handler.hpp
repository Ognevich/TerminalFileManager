#ifndef _WIN_CONSOLE_HANDLER_HPP_
#define _WIN_CONSOLE_HANDLER_HPP_
#include <Windows.h>

struct WinConsoleHandler
{

	HANDLE	handle;
	DWORD	originalMode;

    WinConsoleHandler(HANDLE h);

	~WinConsoleHandler();


};


#endif