/*
** EPITECH PROJECT, 2019
** draw_player.cpp
** File description:
** draw player in sfml mod
*/

#include "my_sfml.hpp"

extern sf::RenderWindow *wd;
extern int mapX;
extern int mapY;


void init_texture(arcd::Ply *ply)
{
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite;
    sf::IntRect rect(0, ((int) ply->direction) * 25, 25, 25);
    if (!texture->loadFromFile(*ply->file))
        std::cout << "Can't open: " << *ply->file << std::endl;
    sprite = new sf::Sprite(*texture, rect);
    ply->texture = (void *) sprite;
}

void draw_player(arcd::Ply *ply, std::vector<std::string> *map)
{
    if (ply->texture == nullptr)
        init_texture(ply);
    sf::Sprite *sprite = (sf::Sprite *) ply->texture;
    sf::IntRect rect(0, ((int) ply->direction) * 25, 25, 25);;
    if (ply->pos.x % 3 == 0 || ply->pos.y % 3 == 0)
        rect.left = 25;
    else
        rect.left = 0;
    sprite->setTextureRect(rect);
    sprite->setPosition(mapX + ply->pos.x * TILE_WIDTH, mapY + ply->pos.y * TILE_HEIGHT);
    wd->draw(*sprite);
}