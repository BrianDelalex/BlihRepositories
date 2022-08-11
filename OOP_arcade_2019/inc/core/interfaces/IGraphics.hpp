/*
** EPITECH PROJECT, 2019
** IGraphics.hpp
** File description:
** graphics interface
*/

#ifndef IGRAPHICS_HPP_
#define IGRAPHICS_HPP_

#include "renderer.hpp"
#include <iostream>

class IGraphics
{
public:
    virtual ~IGraphics() = default;
    virtual void load() = 0;
    virtual const std::string menu(const std::vector<std::string> &gameList) = 0;
    virtual void init_lib() = 0;
    virtual void init(std::string lib) = 0;
    virtual int stop() = 0;
    virtual void next(arcd::render *) = 0;
    virtual void previous(arcd::render *) = 0;
    virtual int display(arcd::render *rd) = 0;
};

#endif