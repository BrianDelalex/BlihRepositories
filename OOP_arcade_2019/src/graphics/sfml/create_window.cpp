/*
** EPITECH PROJECT, 2019
** create_window.cpp
** File description:
** create a sfml window
*/

#include "my_sfml.hpp"

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name)
{
    sf::RenderWindow *wd = new sf::RenderWindow(sf::VideoMode(width, height), name);
    //wd->setFramerateLimit(33);

    return (wd);
}