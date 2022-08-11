/*
** EPITECH PROJECT, 2019
** init.cpp
** File description:
** init sfml window to display game
*/

#include "my_sfml.hpp"

sf::RenderWindow *wd;

extern "C" void init()
{
    wd = create_window(1920, 1080, "Arcade");
}