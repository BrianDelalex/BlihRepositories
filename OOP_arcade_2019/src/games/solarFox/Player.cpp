/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** 
*/

#include "solarFox/Player.hpp"

Player::Player()
{
}

Player::~Player() {}

void Player::init(arcd::Ply ply)
{
    this->_ply = ply;
    this->_lastUpdate = NOW;
    this->_spawn = ply.pos;
    this->_score = 0;
    this->_lastShot = NOW;
}

void Player::move(std::vector<std::string> *map)
{
    if (DURATION<MILLISECONDS>(NOW - this->_lastUpdate).count() < 150)
        return;
    if (this->_ply.direction == arcd::DOWN && !(IS_A_WALL((*map)[this->_ply.pos.y + 1][this->_ply.pos.x])))
        this->_ply.pos.y += 1;
    if (this->_ply.direction == arcd::UP && !(IS_A_WALL((*map)[this->_ply.pos.y - 1][this->_ply.pos.x])))
        this->_ply.pos.y -= 1;
    if (this->_ply.direction == arcd::LEFT && !(IS_A_WALL((*map)[this->_ply.pos.y][this->_ply.pos.x - 1])))
        this->_ply.pos.x -= 1;
    if (this->_ply.direction == arcd::RIGHT && !(IS_A_WALL((*map)[this->_ply.pos.y][this->_ply.pos.x + 1])))
        this->_ply.pos.x += 1;
    if (IS_AN_ENNEMY((*map)[this->_ply.pos.y][this->_ply.pos.x]))
    {
        this->_ply.pos = this->_spawn;
        this->_score -= 200;
    }
    this->_lastUpdate = NOW;
}

arcd::Ply Player::update(arcd::render *rd, uint key, int score)
{
    this->_score += score;
    if (key == 258)
        this->_ply.direction = arcd::DOWN;
    if (key == 259)
        this->_ply.direction = arcd::UP;
    if (key == 260)
        this->_ply.direction = arcd::LEFT;
    if (key == 261)
        this->_ply.direction = arcd::RIGHT;
    move(rd->map);
    return (this->_ply);
}

int Player::get_score()
{
    return (this->_score);
}