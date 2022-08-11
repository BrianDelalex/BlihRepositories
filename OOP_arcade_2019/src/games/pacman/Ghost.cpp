/*
** EPITECH PROJECT, 2019
** Ghost.cpp
** File description:
** 
*/

#include "Ghost.hpp"

Ghost::Ghost(arcd::Ply ghost, TIMEPOINT start)
{
    this->_gh = ghost;
    this->stPoint = start;
    this->_lastUpdate = start;
    this->_passif = true;
    this->_vulnerable = false;
    this->_release = false;
    this->_home = ghost.pos;
    this->tab_move[0] = &go_down;
    this->tab_move[1] = &go_up;
    this->tab_move[2] = &go_left;
    this->tab_move[3] = &go_right;
}

Ghost::~Ghost() {}

bool Ghost::has_start()
{
    if (DURATION<SECONDS>(NOW - this->stPoint).count() < 1)
        return (false);
    return (true);
}

void Ghost::move(std::vector<std::string> *map, arcd::Ply *ply)
{
    // int random = std::rand() % 100;
    // if (_passif && random < 10)
    //     _passif = false;
    // else if (!_passif && random < 50)
    //     _passif = true;
    // if (_vulnerable) {
    //     flee(map, ply);
    //     return;
    // } else if (!_passif) {
    //     hunt(map, ply);
    //     return;
    // }
    //hunt(map, ply);
    void (*tab_move[4])(arcd::Ply *) = {&go_down, &go_up, &go_left, &go_right};
    bool (*tab_check[4])(arcd::Ply *, std::vector<std::string> *, bool) = {&can_go_down, &can_go_up, &can_go_left, &can_go_down};
    if ((*tab_check[_gh.direction])(&_gh, map, _release)) {
        if (std::rand() % 100 < 90) {
            if (_gh.direction == 1 && (*map)[_gh.pos.y][_gh.pos.x] == '%')
                _release = true;
            (*tab_move[_gh.direction])(&_gh);
            return;
        }
    }
    std::vector<void (*)(arcd::Ply *)> funcs;
    for (int i = 0; i < 4; i++)
        if ((*tab_check[i])(&_gh, map, _release))
            funcs.push_back(tab_move[i]);
    int rd_move = std::rand() % ((int) funcs.size());
    if ((*map)[_gh.pos.y][_gh.pos.x] == '%' && rd_move == 1)
        _release = true;
    (*funcs[rd_move])(&_gh);
    this->_lastUpdate = NOW;
}

void Ghost::hunt(std::vector<std::string> *map, arcd::Ply *ply)
{
}

void Ghost::flee(std::vector<std::string> *map, arcd::Ply *ply)
{

}

arcd::Ply Ghost::update(std::vector<std::string> *map, arcd::Ply *ply)
{
    if (!has_start())
        return (this->_gh);
    if (DURATION<MILLISECONDS>(NOW - this->_lastUpdate).count() > 150)
        move(map, ply);
    return (_gh);
}