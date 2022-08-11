/*
** EPITECH PROJECT, 2019
** draw_text.cpp
** File description:
** draw text
*/

#include "my_ncurses.hpp"

extern WINDOW *win;
extern int cursorX;
extern int cursorY;

void draw_text(arcd::String text)
{
    int x = cursorX + text.pos.x;
    int y = cursorY + text.pos.y;
    wmove(win, y, x);
    wprintw(win, text.str.c_str());
}

void draw_texts(std::vector<arcd::String> *texts)
{
    for (int i = 0; i < (int) texts->size(); i++)
        draw_text((*texts)[i]);
}