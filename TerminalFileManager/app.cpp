#include "app.hpp"
#include <conio.h>
#include <iostream>
#include <fstream>

#define DELAY 30

App::App()
	: ui(std::make_unique<UIControler>()),
	fs(std::make_unique<Filesystem>()),
	kb(std::make_unique<KeybControl>()),
	_is_active(true)
{
	setup_keybindings();
}

void App::run()
{
	
	while (_is_active)
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
	auto it = key_actions.find(static_cast<KEYB_SHORTCUTS>(pressed_key));

	if (it != key_actions.end())
	{
		it->second();
	}

}

void App::setup_keybindings()
{
	key_actions[KEYB_SHORTCUTS::ENTER] = [this]() {
		std::vector<std::string> objects = fs->get_objects();

		std::string new_path = objects[kb->get_menu_choice()];

		if (std::filesystem::is_directory(new_path))
		{
			execute_open_file(new_path);
		}
		else if (std::filesystem::is_regular_file(new_path))
		{
			view_file(new_path);
		}
	};

	key_actions[KEYB_SHORTCUTS::F1] = [this]() {
		ui->execute_help_window();
		kb->wait_for_esc();
		ui->clear_screen();
	};

	key_actions[KEYB_SHORTCUTS::ARR_UP] = [this]() {
		kb->move_up();
	};

	key_actions[KEYB_SHORTCUTS::ARR_DOWN] = [this]() {
		kb->move_down(fs->get_objects_size());
	};

	key_actions[KEYB_SHORTCUTS::CTRL_ARR_UP] = [this]() {
		kb->ctrl_move_up();
	};

	key_actions[KEYB_SHORTCUTS::CTR_ARR_DOWN] = [this]() {
		kb->ctrl_move_down(fs->get_objects_size());
	};

	key_actions[KEYB_SHORTCUTS::Q_EXIT] = [this]() {
		_is_active = false;
	};

}

void App::view_file(std::string filepath)
{
	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cerr << "Cannot open file: " << filepath << "\n";
		return;
	}
	if (fs->is_filename_forbidden(filepath))
	{
		std::cout << "Cannot open file " << filepath << "\n";
		return;
	}

	ui->full_clear_screen();
	ui->cursor_home();

	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << "\n";
	}
	file.close();

	kb->wait_for_esc();

	ui->clear_screen();
}

void App::execute_open_file(std::string new_path)
{
	fs->set_current_path(new_path);

	kb->set_menu_choice(0);
	ui->full_clear_screen();
}
