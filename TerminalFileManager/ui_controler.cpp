#include "ui_controler.hpp"
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

void UIControler::print_main_widndow(const std::vector<std::string>& objects, int menu_choice)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		if (menu_choice == i)
		{
			std::cout << "[#]  " << objects[i] << "\n";
		}
		else
		{
			std::cout << "[ ]  " << objects[i] << "\n";
		}
	}

}

void UIControler::clear_screen()
{
	std::cout << "\033[H";
}

void UIControler::add_delay(int delay_ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
}

