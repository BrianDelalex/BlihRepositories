/*
** EPITECH PROJECT, 2019
** draw_map.cpp
** File description:
** draw map with libcaca
*/

#include "my_libcaca.hpp"

extern caca_canvas_t *cv;
extern caca_display_t *dp;
int mapX;
int mapY;

void draw_texts(std::vector<arcd::String> *texts)
{
    for (uint i = 0; i < texts->size(); i++)
    {
        caca_put_str(cv, mapX + (*texts)[i].pos.x, mapY + (*texts)[i].pos.y, (*texts)[i].str.c_str());
    }
}

void draw_player(arcd::Ply *ply)
{
    char c;
    if (ply->direction == arcd::UP)
        c = 'v';
    if (ply->direction == arcd::DOWN)
        c = '^';
    if (ply->direction == arcd::LEFT)
        c = '>';
    if (ply->direction == arcd::RIGHT)
        c = '<';
    caca_put_str(cv, mapX + ply->pos.x, mapY + ply->pos.y, &c);
}

void draw_ennemies(std::vector<arcd::Ply> *ennemies)
{
    for (uint i = 0; i < ennemies->size(); i++)
    {
        caca_put_str(cv, mapX + (*ennemies)[i].pos.x, mapY + (*ennemies)[i].pos.y, "M");
    }
}

void draw_map(std::vector<std::string> *map)
{
    mapX = caca_get_canvas_width(cv) / 2 - (*map)[0].length() / 2;
    mapY = caca_get_canvas_height(cv) / 2 - map->size() / 2;
    for (uint i = 0; i < map->size(); i++)
    {
        for (uint j = 0; j < (*map)[i].length(); j++)
        {
            if ((*map)[i][j] == 'P' || (*map)[i][j] == '!')
                caca_put_str(cv, mapX + j, mapY + i, " ");
            else
                caca_put_str(cv, mapX + j, mapY + i, &(*map)[i][j]);
        }
    }
}
