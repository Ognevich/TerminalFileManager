#include "app.hpp"
#include <conio.h>

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

		size_t pressed_key = kb->define_pressed_key();
		kb->change_menu_choice(pressed_key, objects.size());
	}

}
