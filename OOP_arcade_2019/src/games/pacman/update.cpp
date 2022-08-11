/*
** EPITECH PROJECT, 2019
** update.cpp
** File description:
** updates pacman
*/

#include "pacman.hpp"

extern arcd::render *rd;
extern std::chrono::high_resolution_clock::time_point startTime;
extern Player *ply;
extern std::vector<Ghost *> *ghosts;

extern "C" arcd::render *update(uint key)
{
    *rd->ply = ply->update(key, rd->map);
    rd->texts->at(0).str = std::string("Score: " + std::to_string(ply->getScore()));
    for (int i = 0; i < 4; i++)
      (*rd->ennemies)[i] = (*ghosts)[i]->update(rd->map, rd->ply);
    return (rd);
}