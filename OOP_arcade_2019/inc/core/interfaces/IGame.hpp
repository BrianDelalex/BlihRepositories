/*
** EPITECH PROJECT, 2019
** IGame.hpp
** File description:
** Game interface
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "renderer.hpp"

class IGame
{
public:
    virtual ~IGame() = default;
    virtual void load(std::string game) = 0;
    virtual int start() = 0;
    virtual int stop() = 0;
    virtual arcd::render *next() = 0;
    virtual arcd::render *previous() = 0;
    virtual void init() = 0;
    virtual arcd::render *init_lib() = 0;
    virtual arcd::render *update(uint key) = 0;
private:
};

#endif
