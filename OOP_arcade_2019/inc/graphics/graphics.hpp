/*
** EPITECH PROJECT, 2019
** graphics.hpp
** File description:
** define graphics function
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <vector>
#include <iostream>

extern "C" std::string menu_display(std::vector<std::string> gameList);
extern "C" int display_game(arcd::render *rd);
extern "C" void init();


#endif