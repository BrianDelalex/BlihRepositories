/*
** EPITECH PROJECT, 2019
** Ghost.hpp
** File description:
** 
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "pacman.hpp"
#include <cstdlib>

class Ghost
{
public:
    Ghost(arcd::Ply ghost, TIMEPOINT start);
    ~Ghost();
    bool has_start();
    void move(std::vector<std::string> *map, arcd::Ply *ply);
    void hunt(std::vector<std::string> *map, arcd::Ply *ply);
    void flee(std::vector<std::string> *map, arcd::Ply *ply);
    arcd::Ply update(std::vector<std::string> *map, arcd::Ply *ply);
private:
    arcd::Ply _gh;
    TIMEPOINT stPoint;
    TIMEPOINT _lastUpdate;
    bool _passif;
    bool _vulnerable;
    bool _release;
    arcd::Vec2d _home;
    void (*tab_move[4])(arcd::Ply *);
};

#endif
