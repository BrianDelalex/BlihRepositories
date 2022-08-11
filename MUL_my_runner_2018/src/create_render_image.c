/*
** EPITECH PROJECT, 2018
** create_render_image.c
** File description:
** creates sprite and texture in order to diplay it
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

t_render_image *create_render_image(char const *filepath, float x, float y)
{
    t_render_image *image = malloc(sizeof(t_render_image *));
    sfVector2f pos = {x, y};

    image->texture = sfTexture_createFromFile(filepath, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, pos);
    return (image);
}

void create_background(t_render *render)
{
    render->bg = create_render_image("ressources/background.png", 0, 0);
    render->bg2 = create_render_image("ressources/background2.png", 0, -300);
    render->bg2_b = create_render_image("ressources/background2.png", 2000, -300);
    render->bg3 = create_render_image("ressources/background3.png", 0, 738);
    render->bg3_b = create_render_image("ressources/background3.png", 1920, 738);
    render->bg4 = create_render_image("ressources/background4.png", 0, -450);
    render->bg4_b = create_render_image("ressources/background4.png", 2000, -450);
    render->ply = create_render_image("ressources/spritesheet2.png", 50, 60);
    render->ply->rect = create_animation(250, 230);
    render->zombie = create_render_image("ressources/zombie2.png", 600, 650);
    render->zombie->rect = create_animation(125, 100);
    render->zombie->exist = 1;
}
