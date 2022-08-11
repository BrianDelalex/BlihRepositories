/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** 
*/

#include "Player.hpp"

Player::Player()
{
}

Player::~Player() {}

void Player::init(arcd::Ply player)
{
    this->_ply = player;
    this->_lastUpdate = std::chrono::high_resolution_clock::now();
    this->_score = 0;
}

void Player::move(std::vector<std::string> *map)
{
    switch (this->_ply.direction)
    {
    case arcd::UP:
        if (!is_a_wall((*map)[_ply.pos.y - 1][_ply.pos.x]))
            _ply.pos.y -= 1;
        else if (!is_a_wall((*map)[_ply.pos.y][_ply.pos.x + 1])) {
            _ply.direction = arcd::RIGHT;
            _ply.pos.x += 1;
        } else {
            _ply.direction = arcd::LEFT;
            _ply.pos.x -=1;
        }
        break;
    case arcd::DOWN:
        if (!is_a_wall((*map)[_ply.pos.y + 1][_ply.pos.x]))
            _ply.pos.y += 1;
        else if (!is_a_wall((*map)[_ply.pos.y][_ply.pos.x + 1])) {
            _ply.direction = arcd::RIGHT;
            _ply.pos.x += 1;
        } else {
            _ply.direction = arcd::LEFT;
            _ply.pos.x -= 1;
        }
        break;
    case arcd::LEFT:
        if (!is_a_wall((*map)[_ply.pos.y][_ply.pos.x - 1]))
            _ply.pos.x -= 1;
        else if (!is_a_wall((*map)[_ply.pos.y + 1][_ply.pos.x])) {
            _ply.direction = arcd::DOWN;
            _ply.pos.y += 1;
        } else {
            _ply.direction = arcd::UP;
            _ply.pos.y -= 1;
        }
        break;
    case arcd::RIGHT:
        if (!is_a_wall((*map)[_ply.pos.y][_ply.pos.x + 1]))
            _ply.pos.x += 1;
        else if (!is_a_wall((*map)[_ply.pos.y + 1][_ply.pos.x])) {
            _ply.direction = arcd::DOWN;
            _ply.pos.y += 1;
        } else {
            _ply.direction = arcd::UP;
            _ply.pos.y -= 1;
        }
        break;
    default:
        break;
    }
    if ((*map)[_ply.pos.y][_ply.pos.x] == '.') {
        (*map)[_ply.pos.y][_ply.pos.x] = ' ';
        this->_score+= 100;
    }
}

arcd::Ply Player::update(uint key, std::vector<std::string> *map)
{
    if (key == 258 && (*map)[this->_ply.pos.y + 1][this->_ply.pos.x] != '|' \
        && (*map)[this->_ply.pos.y + 1][this->_ply.pos.x] != '#')
        this->_ply.direction = arcd::DOWN;
    if (key == 259 && (*map)[this->_ply.pos.y - 1][this->_ply.pos.x] != '|' \
        && (*map)[this->_ply.pos.y - 1][this->_ply.pos.x] != '#')
        this->_ply.direction = arcd::UP;
    if (key == 260 && (*map)[this->_ply.pos.y][this->_ply.pos.x - 1] != '|' \
        && (*map)[this->_ply.pos.y][this->_ply.pos.x - 1] != '#')
        this->_ply.direction = arcd::LEFT;
    if (key == 261 && (*map)[this->_ply.pos.y][this->_ply.pos.x + 1] != '|' \
        && (*map)[this->_ply.pos.y][this->_ply.pos.x + 1] != '#')
        this->_ply.direction = arcd::RIGHT;
    if ( std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->_lastUpdate).count() > 150) {
        move(map);
        this->_lastUpdate = std::chrono::high_resolution_clock::now();
    }
    return (_ply);
}

uint Player::getScore()
{
    return (this->_score);
}