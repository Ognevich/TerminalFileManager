#ifndef _UI_CONTROLER_HPP_
#define _UI_CONTROLER_HPP_
#include <vector>
#include <string>


class UIControler {

public:


	void print_widndow(const std::vector<std::string>& objects, int menu_choice);

	void execute_help_window();
	
	void cursor_home();
	void clear_screen();
	void full_clear_screen();

	void add_delay(int delay_ms);



private:

	void print_help_window();

};



#endif