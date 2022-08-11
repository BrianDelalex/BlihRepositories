/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for my_hunter project
*/

#include <SFML/Graphics.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_render_image
{
    sfTexture *texture;
    sfSprite *sprite;
}render_image_t;

#endif