/*
** EPITECH PROJECT, 2019
** draw_player_ennemies.cpp
** File description:
** draw player and ennemies in ncurses mode
*/

#include "my_ncurses.hpp"

extern WINDOW *win;
extern int cursorX;
extern int cursorY;

void draw_player(arcd::Ply ply)
{
    int x = cursorX + ply.pos.x;
    int y = cursorY + ply.pos.y;
    wmove(win, y, x);
    char c;
    if (ply.direction == arcd::UP)
        c = 'v';
    if (ply.direction == arcd::DOWN)
        c = '^';
    if (ply.direction == arcd::LEFT)
        c = '>';
    if (ply.direction == arcd::RIGHT)
        c = '<';
    print_colored_char(win, c, COLOR_PAIR(GREEN));
    wrefresh(win);
}

void draw_ennemie(arcd::Ply *ennemie)
{
    int x = cursorX + ennemie->pos.x;
    int y = cursorY + ennemie->pos.y;
    wmove(win, y, x);
    print_colored_char(win, 'M', COLOR_PAIR(RED));
    wrefresh(win);
}

void draw_ennemies(std::vector<arcd::Ply> *ennemies)
{
    for (int i = 0; i < (int) ennemies->size(); i++)
        draw_ennemie(&((*ennemies)[i]));
}