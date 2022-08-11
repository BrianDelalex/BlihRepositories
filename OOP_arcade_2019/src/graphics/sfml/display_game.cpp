/*
** EPITECH PROJECT, 2019
** display_game.cpp
** File description:
** display the game in sfml mod
*/

#include "my_sfml.hpp"
extern sf::RenderWindow *wd;

int convert_key_code(int key)
{
    if (key == 74)
        return (258);
    if (key == 73)
        return (259);
    if (key == 71)
        return (260);
    if (key == 72)
        return (261);
    if (key == sf::Keyboard::Space)
        return (32);
    if (key == sf::Keyboard::G)
        return (103);
    if (key == sf::Keyboard::H)
        return (104);
    if (key == sf::Keyboard::B)
        return (98);
    if (key == sf::Keyboard::N)
        return (110);
    return (key);
}

extern "C" int display_game(arcd::render *rd)
{
    int key = 0;
    wd->clear();
    draw_map(rd->map);
    draw_player(rd->ply, rd->map);
    draw_ennemies(rd->ennemies);
    draw_texts(rd->texts);
    wd->display();
    sf::Event event;
    wd->pollEvent(event);
    if (event.type == sf::Event::Closed) {
        wd->close();
        return (-1);
    }
    if (event.type == sf::Event::KeyPressed)
        key = event.key.code;
    return (convert_key_code(key));
}