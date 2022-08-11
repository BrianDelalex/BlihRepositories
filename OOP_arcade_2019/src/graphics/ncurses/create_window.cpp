/*
** EPITECH PROJECT, 2019
** create_window.cpp
** File description:
** creating a ncurses window
*/

#include "my_ncurses.hpp"

WINDOW *create_window(int height, int width, int starty, int startx)
{
    WINDOW *win = newwin(height, width, starty, startx);
    
    box(win, 0, 0);
    wrefresh(win);
    return (win);
}