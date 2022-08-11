/*
** EPITECH PROJECT, 2019
** draw_ennemies.cpp
** File description:
** draws ennemies in sfml mod
*/

#include "my_sfml.hpp"
extern sf::RenderWindow *wd;
extern int mapX;
extern int mapY;

void load_ennemie_textures(arcd::Ply *ennemie)
{
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite;
    sf::IntRect rect(0, ((int) ennemie->direction) * 25, 25, 25);
    if (!texture->loadFromFile(*ennemie->file))
        std::cout << "Can't open: " << *ennemie->file << std::endl;
    sprite = new sf::Sprite(*texture, rect);
    ennemie->texture = (void *) sprite;
}

void draw_ennemies(std::vector<arcd::Ply> *ennemies)
{
    for (uint i = 0; i < ennemies->size(); i++) 
    {
        if ((*ennemies)[i].texture == nullptr)
            load_ennemie_textures(&((*ennemies)[i]));
        sf::Sprite *sprite = (sf::Sprite *) (*ennemies)[i].texture;
        sf::IntRect rect(0, ((int) (*ennemies)[i].direction) * 25, 25, 25);
        sprite->setTextureRect(rect);
        sprite->setPosition(mapX + (*ennemies)[i].pos.x * TILE_WIDTH, mapY + (*ennemies)[i].pos.y * TILE_HEIGHT);
        wd->draw(*sprite);
    }
}