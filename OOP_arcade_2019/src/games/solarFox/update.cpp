/*
** EPITECH PROJECT, 2019
** update.cpp
** File description:
** update solarFox
*/

#include "solarFox/solarFox.hpp"

extern arcd::render *rd;
extern Player *ply;
extern std::vector<Bullet> *bullets;

int update_bullet()
{
    int score = 0;
    for (uint i = 0; i < bullets->size(); i++)
    {
        int rtn = (*bullets)[i].update(rd);
        if (rtn == 200 || rtn == -10)
        {
            score += rtn;
            bullets->erase(bullets->begin() + i, bullets->begin() + i + 1);
            i--;
        }
    }
    return (score);
}

void shoot()
{
    Bullet b((*rd->ply).pos.x, (*rd->ply).pos.y, (*rd->ply).direction, rd->texts);
    bullets->push_back(b);
}


extern "C" arcd::render *update(uint key)
{
    if (key == 32)
        shoot();
    int score = update_bullet();
    *rd->ply = ply->update(rd, key, score);
    rd->texts->at(0).str = std::string("Score: " + std::to_string(ply->get_score()));
    return (rd);
}