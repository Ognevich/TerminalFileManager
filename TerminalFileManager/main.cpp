#include <filesystem>
#include <iostream>
#include "app.hpp"
#include "mystr.hpp"
#include "win_console_handler.hpp"

int main()
{
	App app;

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	WinConsoleHandler guard(hIn);

	app.run();


}