#ifndef _KEYB_CONTROLER_
#define _KEYB_CONTROLER_
#include <conio.h>

class KeybControl
{
public:

	KeybControl();

	size_t get_pressed_key();
	void   change_menu_choice(size_t kb_hit, size_t dir_size);

	size_t get_menu_choice();
	void   set_menu_choice(size_t menu_choice);

private:
	int menu_choice;

	enum Key {
		KEY_UP = 72,
		KEY_DOWN = 80,
		CTRL_DOWN = 145,
		CTRL_UP = 141
	};


};

#endif