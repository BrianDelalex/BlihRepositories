/*
** EPITECH PROJECT, 2019
** destroy.cpp
** File description:
** destroy all
*/

#include "my_ncurses.hpp"

extern WINDOW *win;

extern "C" void destroy(__attribute__((unused))arcd::render *rd)
{
    destroy_win(win);
}