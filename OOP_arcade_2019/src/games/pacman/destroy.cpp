/*
** EPITECH PROJECT, 2019
** destroy.cpp
** File description:
** destroy all pacman ressources
*/

#include "pacman.hpp"

extern arcd::render *rd;
extern std::chrono::high_resolution_clock::time_point startTime;
extern Player *ply;
extern std::vector<Ghost *> *ghosts;

extern "C" void destroy()
{
    delete ply;
    for (uint i = 0; i < ghosts->size(); i++)
        delete (*ghosts)[i];
    delete ghosts;
    delete rd->map;
    delete rd->ply;
    delete rd->ennemies;
    delete rd->texts;
}