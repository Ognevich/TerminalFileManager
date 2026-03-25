#ifndef _KEYB_CONTROLER_
#define _KEYB_CONTROLER_
#include <conio.h>
#include <string>

#define K_OFFSET 256

enum class KEYB_SHORTCUTS : size_t {
	CTRL_L	     =  12,
	ENTER        =	13,
	ESC			 =  27,
	F1			 =	59  + K_OFFSET,
	ARR_UP       =	72  + K_OFFSET,
	N_KEY		 =  78,
	ARR_DOWN     =	80  + K_OFFSET,
	n_KEY		 =  110,
	Q_EXIT		 =	113,
	CTRL_ARR_UP  =	141 + K_OFFSET,
	CTR_ARR_DOWN =	145 + K_OFFSET
};

class KeybControl
{
public:

	KeybControl();

	size_t		get_pressed_key();

	size_t		get_menu_choice();
	void		set_menu_choice(size_t menu_choice);

	void		move_up();
	void		move_down(size_t dir_size);
	void		ctrl_move_up();
	void		ctrl_move_down(size_t dir_size);

	std::string get_console_row();

	void		wait_for_esc();

private:
	int menu_choice;


};

#endif