/*
** EPITECH PROJECT, 2018
** create_render_window.c
** File description:
** creates a render window an set it ready to display
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>

sfRenderWindow *create_render_window(int width, int height, int nb_bit_pixel)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, nb_bit_pixel};

    window = sfRenderWindow_create(mode, "my_hunter", sfResize | sfClose, NULL);
    if (!window)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}