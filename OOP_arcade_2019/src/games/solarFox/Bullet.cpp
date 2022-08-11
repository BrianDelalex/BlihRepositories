/*
** EPITECH PROJECT, 2019
** Bullet.cpp
** File description:
** Object to manage solarFox bullet
*/

#include "solarFox/Player.hpp"

Bullet::Bullet(int x, int y, arcd::Direction dir, std::vector<arcd::String> *texts)
{
    this->_pos.x = x;
    this->_pos.y = y;
    this->_dir = dir;
    this->_lastUpdate = NOW;
    arcd::String str;
    str.str = "-";
    str.size = 10;
    str.c = {255, 0, 0};
    str.pos.x = x;
    str.pos.y = y;
    texts->push_back(str);
}

Bullet::~Bullet() {}

void Bullet::kill(arcd::render *rd)
{
    (*rd->map)[this->_pos.y][this->_pos.x] = ' ';
    for (uint i = 0; i < rd->ennemies->size(); i++) 
    {
        if ((*rd->ennemies)[i].pos.x == this->_pos.x && (*rd->ennemies)[i].pos.y == this->_pos.y)
        {
            rd->ennemies->erase(rd->ennemies->begin() + i, rd->ennemies->begin() + i + 1);
            //std::cout << "ENNEMIES KILLED " << rd->ennemies->size() << " REMAINING" << std::endl;
            break;
        }
    }
}

int Bullet::update(arcd::render *rd)
{
    if (DURATION<MILLISECONDS>(NOW - _lastUpdate).count() < 10)
        return 0;
    uint i = 0;
    for (; i < rd->texts->size(); i++)
        if ((*rd->texts)[i].pos.x == (int) this->_pos.x && (*rd->texts)[i].pos.y == (int) this->_pos.y)
            break;
    switch (this->_dir)
    {
    case arcd::DOWN:
        this->_pos.y += 1; break;
    case arcd::UP:
        this->_pos.y -= 1; break;
    case arcd::LEFT:
        this->_pos.x -= 1; break;
    case arcd::RIGHT:
        this->_pos.x += 1; break;
    default:
        break;
    }
    if (IS_AN_ENNEMY((*rd->map)[this->_pos.y][this->_pos.x]))
    {
        kill(rd);
        rd->texts->erase(rd->texts->begin() + i, rd->texts->begin() + i + 1);
        return (200);
    } else if(IS_A_WALL((*rd->map)[this->_pos.y][this->_pos.x]))
    {
        rd->texts->erase(rd->texts->begin() + i, rd->texts->begin() + i + 1);
        return (-10);
    } else
    {
        (*rd->texts)[i].pos.x = this->_pos.x;
        (*rd->texts)[i].pos.y = this->_pos.y;
        return (0);
    }
    
}