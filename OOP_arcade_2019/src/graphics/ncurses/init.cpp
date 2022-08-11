/*
** EPITECH PROJECT, 2019
** init.cpp
** File description:
** initialisation of ncurses components
*/

#include "my_ncurses.hpp"

WINDOW *win;

extern "C" void init()
{
    initscr();
    cbreak();
    noecho();
    refresh();
    curs_set(0);
    win = create_window(LINES, COLS, 0, 0);
    start_color();
    init_pair(CYAN_BLUE, COLOR_CYAN, COLOR_BLUE);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    timeout(150);
    wrefresh(win);
}