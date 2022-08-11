/*
** EPITECH PROJECT, 2019
** init_solarFox.cpp
** File description:
** Initialize solarFow games
*/

#include "solarFox/solarFox.hpp"

arcd::render *rd;
Player *ply;
std::vector<Bullet> *bullets;

void add_ennemie(uint i, uint j)
{
    arcd::Ply ply;
    ply.pos.x = j;
    ply.pos.y = i;
    ply.direction = arcd::DOWN;
    ply.texture = nullptr;
    std::string *path =  new std::string(PROJECT_DIR);
    path->append("/ressources/games/solarFox/ennemi.png");
    ply.file = path;
    rd->ennemies->push_back(ply);
}

void add_player(uint i, uint j)
{
    rd->ply->pos.x = j;
    rd->ply->pos.y = i;
    rd->ply->direction = arcd::LEFT;
    std::string *path =  new std::string(PROJECT_DIR);
    path->append("/ressources/games/solarFox/player.png");
    rd->ply->file = path;
    rd->ply->texture = nullptr;
}

void set_position()
{
    for (uint i = 0; i < rd->map->size(); i++) 
    {
        for (uint j = 0; j < (*rd->map)[i].length(); j++)
        {
            if ((*rd->map)[i][j] == '!') {
                add_ennemie(i, j);
            }
            if ((*rd->map)[i][j] == 'P') {
                add_player(i, j);
            }
        }
    }
}

void init_map()
{
    std::string path = PROJECT_DIR;
    rd = new arcd::render;
    rd->map = new std::vector<std::string>;
    rd->ply = new arcd::Ply;
    rd->ennemies = new std::vector<arcd::Ply>;
    rd->texts = new std::vector<arcd::String>;
    std::string str;

    path.append("/ressources/games/solarFox/map0.txt");
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        throw MapInitError("Can't open map file", "Error in map Initialisation");
    while (std::getline(file, str, '\n') && str != "INFOS")
    {
        rd->map->push_back(str);
    }
    set_position();
}

extern "C" arcd::render *init()
{
    try
    {
        init_map();
    }
    catch(const MapInitError& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
    }
    ply = new Player;
    ply->init(*rd->ply);
    arcd::String score;
    score.str = "Score: 0";
    score.pos = { ((int)(*rd->map)[0].length() / 2) , -2};
    score.size = 32;
    score.c = {255, 255, 255};
    rd->texts = new std::vector<arcd::String>;
    rd->texts->push_back(score);
    bullets = new std::vector<Bullet>;
    return (rd);
}