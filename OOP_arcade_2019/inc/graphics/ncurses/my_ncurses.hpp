/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "renderer.hpp"
#include <ncurses.h>
#include <vector>
#include <iostream>

enum COLOR
{
    CYAN_BLUE = 1,
    RED = 2,
    GREEN = 3,
};

WINDOW *create_window(int height, int width, int starty, int startx);
void draw_map(std::vector<std::string> *map);
std::vector<arcd::Vec2d> create_menu(WINDOW *win, std::vector<std::tuple<std::string, std::string>> *banners);
void print_colored_char(WINDOW *win, char c, int color);
void draw_arrow(WINDOW *win, int x, int y, std::string arrow);
void draw_player(arcd::Ply);
void draw_ennemies(std::vector<arcd::Ply> *ennemies);
void draw_texts(std::vector<arcd::String> *texts);
void destroy_win(WINDOW *local_win);

#endif