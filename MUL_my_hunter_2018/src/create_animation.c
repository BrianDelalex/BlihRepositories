/*
** EPITECH PROJECT, 2018
** create_animation.c
** File description:
** creates animation for my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset > max_value)
        rect->left = 0;
    else
        rect->left += offset;
}

sfIntRect create_animation(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    return (rect);
}
