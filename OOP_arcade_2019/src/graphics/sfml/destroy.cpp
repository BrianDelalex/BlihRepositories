/*
** EPITECH PROJECT, 2019
** destroy.cpp
** File description:
** destroy all
*/

#include "my_sfml.hpp"

extern sf::RenderWindow *wd;

extern "C" void destroy(arcd::render *rd)
{
    wd->close();
}