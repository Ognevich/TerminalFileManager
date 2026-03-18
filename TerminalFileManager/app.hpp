#ifndef _APP_HPP_
#define _APP_HPP_
#include <memory>
#include "filesystem.hpp"
#include "ui_controler.hpp"
#include "keyb_controler.hpp"
#include <functional>
#include <unordered_map>

class App {

public:

	App();



	void run();

private:

	void		execute_key_action(size_t pressed_key);
	void		setup_keybindings();

	void		view_file(std::string filepath);
	void		execute_open_file(std::string new_path);

	bool		_is_active;

	std::unique_ptr<UIControler>	ui;
	std::unique_ptr<Filesystem>		fs;
	std::unique_ptr<KeybControl>	kb;

	std::unordered_map<KEYB_SHORTCUTS, std::function<void()>> key_actions;
};

#endif