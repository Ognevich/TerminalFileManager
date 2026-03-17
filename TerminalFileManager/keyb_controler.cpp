#include "keyb_controler.hpp"
#include <iostream>

KeybControl::KeybControl()
    : menu_choice(0)
{

}

size_t KeybControl::get_pressed_key()
{
    
    int ch = _getch();

    if (ch == 0 || ch == 224)
    {
        ch = _getch();

        return ch + K_OFFSET;

    }
    return ch;
}

size_t KeybControl::get_menu_choice()
{
    return this->menu_choice;
}

void KeybControl::set_menu_choice(size_t menu_choice)
{
    this->menu_choice = menu_choice;
}

void KeybControl::move_up()
{
    if (menu_choice > 0) menu_choice--;
}

void KeybControl::move_down(size_t dir_size)
{
    if (menu_choice < (dir_size - 1)) menu_choice++;
}

void KeybControl::ctrl_move_up()
{
    if (menu_choice > 0) menu_choice = 0;
}

void KeybControl::ctrl_move_down(size_t dir_size)
{
    if (menu_choice < (dir_size - 1)) menu_choice = dir_size - 1;
}

void KeybControl::wait_for_esc()
{
    size_t pressed;

    do {

        pressed = _getch();

    } while (pressed != static_cast<size_t>(KEYB_SHORTCUTS::ESC));

}

