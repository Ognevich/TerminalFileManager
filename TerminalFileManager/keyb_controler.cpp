#include "keyb_controler.hpp"

KeybControl::KeybControl()
    : menu_choice(0)
{

}

size_t KeybControl::get_pressed_key()
{
    
    int ch = _getch();

    if (ch == 224)
    {
        ch = _getch();

        return ch;

    }
    return ch;
}

void KeybControl::change_menu_choice(size_t kb_hit, size_t dir_size)
{
    switch (kb_hit)
    {
    case KeybControl::KEY_UP:
        if (menu_choice > 0) menu_choice--;
        break;
    case KeybControl::KEY_DOWN:
        if (menu_choice < (dir_size-1)) menu_choice++;
        break;
    case KeybControl::CTRL_UP:
        if (menu_choice > 0) menu_choice = 0;
        break;
    case KeybControl::CTRL_DOWN:
        if (menu_choice <  (dir_size-1)) menu_choice = dir_size-1;
        break;
    default:
        break;
    }
    return;
}

size_t KeybControl::get_menu_choice()
{
    return this->menu_choice;
}

void KeybControl::set_menu_choice(size_t menu_choice)
{
    this->menu_choice = menu_choice;
}

