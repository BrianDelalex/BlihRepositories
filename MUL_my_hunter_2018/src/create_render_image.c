/*
** EPITECH PROJECT, 2018
** create_render_image.c
** File description:
** creates sprite and texture in order to diplay it
*/

#include "struct.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

void my_putchar(char c);

render_image_t *create_render_image(char const *filepath, float x, float y)
{
    render_image_t *image = malloc(sizeof(render_image_t));
    sfVector2f pos = {x, y};

    image->texture = malloc(sizeof(sfTexture *));
    image->texture = sfTexture_createFromFile(filepath, NULL);
    image->sprite = malloc(sizeof(sfSprite *));
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, pos);
    return (image);
}
