/*
** EPITECH PROJECT, 2019
** renderer.hpp
** File description:
** defines displayable comp
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "iostream"
#include "vector"

namespace arcd
{
    enum Direction 
    {
        DOWN,
        UP,
        LEFT,
        RIGHT
    };

    struct vector2d_s
    {
        uint x;
        uint y;
    };

    typedef struct vector2d_s Vec2d;

    struct vector2ds_s
    {
        int x;
        int y;
    };

    typedef struct vector2ds_s Vec2ds;

    struct color_rgb_s
    {
        uint r;
        uint g;
        uint b;
    };

    typedef struct color_rgb_s Color;

    struct arcade_string_s
    {
        std::string str;
        Vec2ds pos;
        uint size;
        Color c;
    };

    typedef struct arcade_string_s String;

    struct player_s
    {
        Vec2d pos;
        void *texture;
        std::string *file;
        Direction direction;
    };

    typedef struct player_s Ply;

    struct renderer_s
    {
        std::vector<std::string> *map;
        std::vector<String> *texts;
        Ply *ply;
        std::vector<Ply> *ennemies;
        std::string gameName;
        std::string name;
    };

    typedef struct renderer_s render;
}

#endif