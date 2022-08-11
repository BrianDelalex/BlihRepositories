/*
** EPITECH PROJECT, 2019
** GameManager.hpp
** File description:
** 
*/

#ifndef GAMEMANAGER_HPP_
#define GAMEMANAGER_HPP_

#include "IGame.hpp"
#include "renderer.hpp"
#include "utils.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include "GameManagerError.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

class GameManager : public IGame
{
public:
    GameManager();
    ~GameManager();
    void init();
    void load(std::string game);
    int start();
    int stop();
    arcd::render *next();
    arcd::render *previous();
    arcd::render *init_lib();
    arcd::render *update(uint key);
    std::vector<std::string> getGameList();
    std::vector<std::string> getLibList();
private:
    std::vector<std::string> games;
    void *handle;
    arcd::render * (*updateSym)(uint);
    uint curGame;
};

#endif
