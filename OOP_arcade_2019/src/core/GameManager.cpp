/*
** EPITECH PROJECT, 2019
** GameManager.cpp
** File description:
** 
*/

#include "GameManager.hpp"

GameManager::GameManager()
{
}

void GameManager::init()
{
    DIR *gamesDir = opendir("./games");
    struct dirent *nextEnt;

    if (gamesDir == NULL)
        throw GameManagerError("Can't open games directory" ,"GameManager can't be initialised");
    while ((nextEnt = readdir(gamesDir)) != NULL)
        if (nextEnt->d_name && nextEnt->d_name[0] != '.')
            this->games.push_back(std::string(nextEnt->d_name));
}

GameManager::~GameManager() {}

void GameManager::load(std::string game)
{
    int i = 0;
    for (; i < (int) this->games.size() && formating_name_to_libName(game) != this->games.at(i); i++);
    if (i == (int) this->games.size())
        throw GameManagerError(std::string(game + " not found."), "GameManagerError can't load game");
    this->curGame = i;
    this->handle = dlopen(std::string("./games/" + this->games.at(i)).c_str(), RTLD_NOW);
    std::cout << this->games.at(i) << std::endl;
    if (this->handle == NULL)
        throw GameManagerError(dlerror(), "GameManagerError dlopen()");
}

int GameManager::start()
{
    return (0);
}

int GameManager::stop()
{
    return (0);
}

arcd::render *GameManager::next()
{
    void (*destroyer)() = (void (*)()) dlsym(this->handle, "destroy");
    (*destroyer)();
    if (this->curGame == this->games.size() - 1)
        this->curGame = 0;
    else
        this->curGame += 1;
    load(formating_lib_name(this->games[this->curGame]));
    return (init_lib());
}

arcd::render *GameManager::previous()
{
    void (*destroyer)() = (void (*)()) dlsym(this->handle, "destroy");
    (*destroyer)();
    if (this->curGame == 0)
        this->curGame = this->games.size() -1;
    else
        this->curGame -= 1;
    load(formating_lib_name(this->games[this->curGame]));
    return (init_lib());
}

arcd::render *GameManager::init_lib()
{
    arcd::render *(*init)() = (arcd::render *(*)()) dlsym(this->handle, "init");
    if (init == NULL)
        throw GameManagerError(dlerror(), "GameManagerError init_lib()");
    this->updateSym = (arcd::render *(*)(uint)) dlsym(this->handle, "update");
    if (this->updateSym == NULL)
        throw GameManagerError(dlerror(), "GameManagerError init_lib()");
    arcd::render *rd = (*init)();
    return (rd);
}

arcd::render *GameManager::update(uint key)
{
    arcd::render *rd = (*updateSym)(key);
    return (rd);
}

std::vector<std::string> GameManager::getGameList()
{
    std::vector<std::string> gameList;
    std::string str;

    for (int i = 0; i < (int) this->games.size(); i++)
    {
        str = formating_lib_name(this->games[i]);
        gameList.push_back(str);
    }
    return (gameList);
}

std::vector<std::string> GameManager::getLibList()
{
    return (this->games);
}