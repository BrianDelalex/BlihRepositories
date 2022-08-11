/*
** EPITECH PROJECT, 2019
** GraphicsManager.cpp
** File description:
** 
*/

#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager()
{
}

GraphicsManager::~GraphicsManager() {}

void GraphicsManager::load()
{
    this->handle = dlopen(std::string("./lib/" + this->_libs[this->_curLib]).c_str(), RTLD_NOW);
    if (this->handle == NULL)
        throw GraphicsManagerError(dlerror(), "GraphicsManagerError dlopen()");
}

const std::string GraphicsManager::menu(const std::vector<std::string> &gameList)
{
    if (this->handle == NULL)
        throw GraphicsManagerError("Can't open menu any graphics lib loaded", "GraphicsManagerError menu()");
    this->menuSym = (std::string (*)(std::vector<std::string>)) dlsym(this->handle, "menu_display");
    if (this->menuSym == NULL) 
    {
        throw GraphicsManagerError(dlerror(), "GraphicsManagerError dlsym()");
    }
    return ((*this->menuSym)(gameList));
}

void GraphicsManager::init_lib()
{
    void (*init)() = (void(*)()) dlsym(this->handle, "init");
    if (init == NULL)
        throw GraphicsManagerError(dlerror(), "GraphicsManagerError init_lib()");
    (*init)();
    this->displaySim = (int(*)(arcd::render *)) dlsym(this->handle, "display_game");
    if (this->displaySim == NULL)
        throw GraphicsManagerError(dlerror(), "GraphicsManagerError init_lib()");
}

void GraphicsManager::init(std::string lib)
{
    DIR *libDir = opendir("./lib");
    struct dirent *nextEnt;

    if (libDir == NULL)
        throw GraphicsManagerError("Can't open lib directory" ,"GraphicsManager can't be initialised");
    while ((nextEnt = readdir(libDir)) != NULL)
        if (nextEnt->d_name && nextEnt->d_name[0] != '.')
            this->_libs.push_back(std::string(nextEnt->d_name));
    int i = 0;
    for (; i < (int) this->_libs.size() && this->_libs[i] != lib; i++);
    if (i == (int) this->_libs.size())
        throw GraphicsManagerError("Lib: " + lib + " not found", "GraphicsManagerError init");
    this->_curLib = i;
    load();
}

int GraphicsManager::stop()
{
    return (0);
}

void GraphicsManager::next(arcd::render *rd)
{
    void (*destroyer)(arcd::render *) = (void(*)(arcd::render *)) dlsym(this->handle, "destroy"); 
    (*destroyer)(rd);
    if (this->_curLib == ((uint) this->_libs.size()) - 1)
        this->_curLib = 0;
    else
        this->_curLib += 1;
    load();
    init_lib();
}

void GraphicsManager::previous(arcd::render *rd)
{
    void (*destroyer)(arcd::render *) = (void(*)(arcd::render *)) dlsym(this->handle, "destroy"); 
    (*destroyer)(rd);
    if (this->_curLib == 0)
        this->_curLib = ((uint) this->_libs.size()) - 1;
    else
        this->_curLib -= 1;
    load();
    init_lib();
}

int GraphicsManager::display(arcd::render *rd)
{
    if (this->displaySim == NULL)
        throw GraphicsManagerError("Can't display symbol display_game not set", "GraphicsManagerError");
    return ((*displaySim)(rd));
}

std::vector<std::string> GraphicsManager::getLib()
{
    return (this->_libs);
}
