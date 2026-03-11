#ifndef _APP_HPP_
#define _APP_HPP_
#include <memory>
#include "filesystem.hpp"
#include "ui_controler.hpp"
#include "keyb_controler.hpp"

class App {

public:

	App();



	void run();

private:

	std::unique_ptr<UIControler> ui;
	std::unique_ptr<Filesystem> fs;
	std::unique_ptr<KeybControl> kb;

};

#endif