/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** 
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "solarFox/solarFox.hpp"

class Bullet
{
public:
    Bullet(int x, int y, arcd::Direction dir, std::vector<arcd::String> *texts);
    ~Bullet();
    int update(arcd::render *rd);
    void kill(arcd::render *rd);
private:
    arcd::Vec2d _pos;
    arcd::Direction _dir;
    TIMEPOINT _lastUpdate;
};

class Player
{
public:
    Player();
    ~Player();
    void init(arcd::Ply ply);
    arcd::Ply update(arcd::render *rd, uint key, int score);
    void move(std::vector<std::string> *map);
    int get_score();
private:
    TIMEPOINT _lastUpdate;
    TIMEPOINT _lastShot;
    std::vector<Bullet> bullets;
    arcd::Ply _ply;
    arcd::Vec2d _spawn;
    int _score;
};

#endif
