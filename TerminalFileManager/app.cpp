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
		std::vector<std::string> objects = fs->get_current_objects();

		ui->clear_screen();

		while (_kbhit()) _getch();

		ui->print_main_widndow(objects,kb->get_menu_choice());
		ui->add_delay(DELAY);

		size_t pressed_key = kb->get_pressed_key();
		execute_key_action(pressed_key, objects);
	
	}

}

void App::execute_key_action(size_t pressed_key, std::vector<std::string> & objects)
{
	if (pressed_key == 13)
	{

		std::string new_path = objects[kb->get_menu_choice()];

		fs->execute_enter(new_path);
	}
	else
	{
		kb->change_menu_choice(pressed_key, objects.size());
	}

}
