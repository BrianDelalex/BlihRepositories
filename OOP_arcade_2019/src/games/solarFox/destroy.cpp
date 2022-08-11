/*
** EPITECH PROJECT, 2019
** destroy.cpp
** File description:
** destroy all solarFox ressources 
*/

#include "solarFox/solarFox.hpp"

extern arcd::render *rd;
extern Player *ply;
extern std::vector<Bullet> *bullets;

extern "C" void destroy()
{
    delete bullets;
    delete ply;
    delete rd->ply;
    for (uint i = 0; i < rd->texts->size(); i++)
        (*rd->texts)[i].str.clear();
    delete rd->texts;
    delete rd->ennemies;
    delete rd->map;
}