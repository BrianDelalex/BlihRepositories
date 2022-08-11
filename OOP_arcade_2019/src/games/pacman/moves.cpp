/*
** EPITECH PROJECT, 2019
** moves.cpp
** File description:
** movement function for pacman
*/

#include "pacman.hpp"

void go_up(arcd::Ply *ply)
{
    ply->pos.y = ply->pos.y - 1;
    ply->direction = arcd::UP;
}

void go_down(arcd::Ply *ply)
{
    ply->pos.y = ply->pos.y + 1;
    ply->direction = arcd::DOWN;
}

void go_left(arcd::Ply *ply)
{
    ply->pos.x = ply->pos.x - 1;
    ply->direction = arcd::LEFT;
}

void go_right(arcd::Ply *ply)
{
    ply->pos.x = ply->pos.x + 1;
    ply->direction = arcd::RIGHT;
}

bool can_go_up(arcd::Ply *ply, std::vector<std::string> *map, bool release)
{
    return (!is_a_wall((*map)[ply->pos.y - 1][ply->pos.x]) || (!release && is_a_door((*map)[ply->pos.y - 1][ply->pos.x])));
}

bool can_go_down(arcd::Ply *ply, std::vector<std::string> *map, bool release)
{
    return (!is_a_wall((*map)[ply->pos.y + 1][ply->pos.x]) || (!release  && is_a_door((*map)[ply->pos.y + 1][ply->pos.x])));
}

bool can_go_left(arcd::Ply *ply, std::vector<std::string> *map, bool release)
{
    return (!is_a_wall((*map)[ply->pos.y][ply->pos.x - 1]) || (!release && is_a_door((*map)[ply->pos.y][ply->pos.x - 1])));
}

bool can_go_right(arcd::Ply *ply, std::vector<std::string> *map, bool release)
{
    return (!is_a_wall((*map)[ply->pos.y][ply->pos.x + 1]) || (!release && is_a_door((*map)[ply->pos.y][ply->pos.x + 1])));
}