/*
** EPITECH PROJECT, 2019
** draw_menu.cpp
** File description:
** draw menu in NCURSES
*/

#include "my_ncurses.hpp"
#include "renderer.hpp"
#include <tuple>
#include <vector>

#define BANNERS_SIZE 50

void draw_banner(WINDOW *win, std::string banner, int cursorX, int cursorY)
{
    int save = cursorX;
    for (int i = 0; i < (int) banner.length(); i++)
    {
        if (banner[i] == 'E')
        {
            cursorY++;
            cursorX = save;
        } else {
            print_colored_char(win, banner[i], COLOR_PAIR(1));
            cursorX++;
        }
        wmove(win, cursorY, cursorX);
    }
}

void draw_arrow(WINDOW *win, int x, int y, std::string arrow)
{
    int cursorX = x - 4;
    int cursorY = y + 7;
    wmove(win, cursorY, cursorX);
    for (int i = 0; i < (int) arrow.length(); i++)
    {       
        if (arrow[i] == 'E')
        {
            cursorY++;
            cursorX = x - 4;
        } 
        else if (arrow[i] == ' ') {
            wprintw(win, "");
            cursorX++;
        } 
        else
        {
            wattron(win, A_BLINK);
            print_colored_char(win, arrow.c_str()[i], COLOR_PAIR(2));
            wattroff(win, A_BLINK);
            cursorX++;
        }
        wmove(win, cursorY, cursorX);
    }
    wrefresh(win);
}

std::vector<arcd::Vec2d> create_menu(WINDOW *win, std::vector<std::tuple<std::string, std::string>> *banners)
{
    std::vector<arcd::Vec2d> pos;
    arcd::Vec2d vec;
    int cursorX = ((COLS / 4) - (BANNERS_SIZE / 2));
    int cursorY = (LINES / 2) - 2;
    wmove(win, cursorY, cursorX);
    for (int i = 0; i < (int) banners->size(); i++)
    {
        vec.x = (uint) cursorX + (BANNERS_SIZE / 2);
        vec.y = (uint) cursorY;
        pos.push_back(vec);        
        draw_banner(win, std::get<1>(banners->at(i)) , cursorX, cursorY);
        cursorY = (LINES / 2) - 2;
        cursorX = ((COLS / 2) + (COLS / 4) - (BANNERS_SIZE / 2));
        wmove(win, cursorY, cursorX);
    }
    wrefresh(win);
    return (pos);
}