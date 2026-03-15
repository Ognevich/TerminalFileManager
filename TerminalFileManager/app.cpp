#include "app.hpp"
#include <conio.h>
#include <iostream>

#define DELAY 30

App::App()
	: ui(std::make_unique<UIControler>()),
	fs(std::make_unique<Filesystem>()),
	kb(std::make_unique<KeybControl>())
{

}

void App::run()
{
	
	while (1)
	{

		fs->set_objects(fs->get_current_path());

		ui->cursor_home();

		while (_kbhit()) _getch();

		ui->print_widndow(fs->get_objects(), kb->get_menu_choice());
		ui->add_delay(DELAY);

		size_t pressed_key = kb->get_pressed_key();
		execute_key_action(pressed_key);
	
	}

}

void App::execute_key_action(size_t pressed_key)
{
	std::vector<std::string> objects = fs->get_objects();

	if (pressed_key == 13)
	{

		std::string new_path = objects[kb->get_menu_choice()];
		bool res = fs->set_current_path(new_path);
		
		if (res)
		{
			kb->set_menu_choice(0);
			ui->clear_screen();
		}

	}
	else
	{
		kb->change_menu_choice(pressed_key, objects.size());
	}

}
