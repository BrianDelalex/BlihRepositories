/*
** EPITECH PROJECT, 2019
** init_pacman.cpp
** File description:
** init the game
*/

#include "pacman.hpp"
#include "MapInitError.hpp"
#include <fstream>
#include <stdexcept>

arcd::render *rd;
std::chrono::high_resolution_clock::time_point startTime;
Player *ply;
std::vector<Ghost *> *ghosts;

void set_position(std::vector<std::string> info)
{
    rd->ennemies = new std::vector<arcd::Ply>;
    int ghostX, ghostY;
    rd->ply->pos.x = (uint) std::stoi(info[1].substr(0, info[1].find_first_of(" ", 0)));
    rd->ply->pos.y = (uint) std::stoi(info[1].substr(info[1].find_first_of(" ", 0), info[1].length() - info[1].find_first_of(" ", 0)));
    ghostX = std::stoi(info[3].substr(0, info[3].find_first_of(" ", 0)));
    ghostY = std::stoi(info[3].substr(info[3].find_first_of(" ", 0), info[3].length() - info[3].find_first_of(" ", 0)));
    for (int i = 0; i < 4; i++) {
            arcd::Ply newGhost;
            newGhost.pos.x = ghostX;
            newGhost.pos.y = ghostY;
            rd->ennemies->push_back(newGhost);
    }
    if (( rd->ply->pos.y > (uint) rd->map->size() || rd->ply->pos.x > (uint) rd->map->at(0).length())\
        && (*rd->map)[rd->ply->pos.y][rd->ply->pos.x] != '.'
        && (*rd->map)[rd->ply->pos.y][rd->ply->pos.x] != '*') {
        throw MapInitError("Map wrong format (player wrong position)", "MapInitError");
    }
}

arcd::render *init_map(std::string map_name)
{
    std::string path = std::string(PROJECT_DIR);
    rd = new arcd::render;
    rd->map = new std::vector<std::string>;
    rd->ply = new arcd::Ply;
    std::vector<std::string> info;
    std::string str;

    path.append(std::string(MAP_DIR));
    path.append(map_name);
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        throw MapInitError("Can't open map file", "Error in map Initialisation");
    while (std::getline(file, str, '\n') && str != "INFOS")
    {
        rd->map->push_back(str);
    }
    while (std::getline(file, str, '\n'))
    {
        info.push_back(str);
    }
    if (info.size() != 4)
        throw MapInitError("Map wrong format (positions missing)" + path, "MapInitError");
    try
    {
        set_position(info);
    }
    catch(const MapInitError& e)
    {
        throw e;
    }
    return (rd);
}

void init_set_texture()
{
    std::string path = PROJECT_DIR;
    for (uint i = 0; i < 4; i++) {
        (*rd->ennemies)[i].texture = nullptr;
        (*rd->ennemies)[i].file = new std::string(path + "/ressources/games/pacman/ghost" + std::to_string(i) + ".png");
    }
}

extern "C" arcd::render *init()
{
    try
    {
        rd = init_map("map0.txt");
    }
    catch(const MapInitError& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
        exit(84);
    }
    for (int i = 0 ; i < (int) rd->ennemies->size(); i++)
        rd->ennemies->at(i).direction = arcd::UP;
    rd->ply->direction = arcd::LEFT;
    startTime = std::chrono::high_resolution_clock::now();
    rd->ply->texture = nullptr;
    std::string file = PROJECT_DIR;
    file.append("/ressources/games/pacman/pacman_spritesheet.png");
    rd->ply->file = new std::string(file);
    init_set_texture();
    ply = new Player;
    ply->init(*rd->ply);
    arcd::String score;
    score.str = "Score: 0";
    score.pos = { ((int)(*rd->map)[0].length()) / 2, -3};
    score.size = 32;
    score.c = {255, 255, 255};
    rd->texts = new std::vector<arcd::String>;
    rd->texts->push_back(score);
    ghosts = new std::vector<Ghost *>;
    for (int i = 0; i < 4; i++) {
        ghosts->push_back(new Ghost((*rd->ennemies)[i], startTime));
    }
    std::srand(std::time(nullptr));
    return (rd);
}