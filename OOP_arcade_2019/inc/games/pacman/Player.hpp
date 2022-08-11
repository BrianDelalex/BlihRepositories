/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** 
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "renderer.hpp"
#include "pacman.hpp"
#include <chrono>

class Player
{
public:
    Player();
    ~Player();
    void init(arcd::Ply player);
    arcd::Ply update(uint key, std::vector<std::string> *map);
    void move(std::vector<std::string> *map);
    uint getScore();
private:
    arcd::Ply _ply;
    std::chrono::high_resolution_clock::time_point _lastUpdate;
    uint _score;
};

#endif
