/*
** EPITECH PROJECT, 2019
** GraphicsManager.hpp
** File description:
** Handler for Graphics libs
*/

#ifndef GRAPHICSMANAGER_HPP_
#define GRAPHICSMANAGER_HPP_

#include "renderer.hpp"
#include "IGraphics.hpp"
#include "GraphicsManagerError.hpp"
#include "utils.hpp"
#include <iostream>
#include <dirent.h>
#include <dlfcn.h>

class GraphicsManager : public IGraphics
{
public:
    GraphicsManager();
    ~GraphicsManager();
    void load();
    const std::string menu(const std::vector<std::string> &gameList);
    void init_lib();
    void init(std::string lib);
    int stop();
    void next(arcd::render *rd);
    void previous(arcd::render *rd);
    int display(arcd::render *rd);
    std::vector<std::string> getLib();
private:
    std::vector<std::string> _libs;
    uint _curLib;
    void *handle;
    int (*displaySim)(arcd::render *);
    std::string (*menuSym)(std::vector<std::string>);
};

#endif
