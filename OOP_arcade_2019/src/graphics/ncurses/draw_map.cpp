/*
** EPITECH PROJECT, 2019
** draw_map.cpp
** File description:
** draw the game map
*/

#include "renderer.hpp"
#include "my_ncurses.hpp"
#include <vector>
#include <ctype.h>

extern WINDOW *win;
int cursorX;
int cursorY;

void print_colored_char(WINDOW *win, char c, int color)
{
    if (isprint(c))
    {
        wattron(win, color);
        waddch(win, c);
        wattroff(win, color);
    }
}

void draw_map(std::vector<std::string> *map)
{
    cursorX = ((COLS / 2) - (map->at(0).length() / 2));
    cursorY = ((LINES / 2) - (map->size() / 2));
    wmove(win, cursorY, cursorX);
    for (int i = 0; i < (int) map->size(); i++)
    {
        for (int j = 0; j < (int) map->at(i).length(); j++)
        {
            if (map->at(i)[j] == '#' || map->at(i)[j] == '%')
                print_colored_char(win, '#', COLOR_PAIR(1));
            else if (map->at(i)[j] == '|')
                wprintw(win, " ");
            else if (map->at(i)[j] == ' ')
                wprintw(win, &(map->at(i)[j]));
            else if (map->at(i)[j] == '.')
                wprintw(win, &(map->at(i)[j]));
            else if (map->at(i)[j] == '*')
                print_colored_char(win, 'o', COLOR_PAIR(RED));
            else
                wprintw(win, " ");
            cursorX++;
            wmove(win, cursorY, cursorX);
        }
        cursorY++;
        cursorX = ((COLS / 2) - (map->at(0).length() / 2));
        wmove(win, cursorY, cursorX);
    }
    wrefresh(win);
    cursorX = ((COLS / 2) - (map->at(0).length() / 2));
    cursorY = ((LINES / 2) - (map->size() / 2));
}