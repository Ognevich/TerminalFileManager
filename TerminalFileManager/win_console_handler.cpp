#include "win_console_handler.hpp"

WinConsoleHandler::WinConsoleHandler(HANDLE h)
{
    handle = h;
    GetConsoleMode(handle, &originalMode);

    DWORD mode = originalMode;

    mode &= ~ENABLE_LINE_INPUT;
    mode &= ~ENABLE_ECHO_INPUT;
    mode &= ~ENABLE_PROCESSED_INPUT;
    mode &= ~ENABLE_QUICK_EDIT_MODE;

    SetConsoleMode(handle, mode);
}

WinConsoleHandler::~WinConsoleHandler()
{
    SetConsoleMode(handle, originalMode);
}
