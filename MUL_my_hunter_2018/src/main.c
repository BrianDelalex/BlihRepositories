/*
** EPITECH PROJECT, 2018
** main.C
** File description:
** main function for my_hunter project
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include "my.h"
#include "struct.h"
#include <unistd.h>

void call_draw_functions(sfRenderWindow *wdw, render_image_t *bg,
render_image_t *duck, sfText *scoreboard)
{
    sfRenderWindow_clear(wdw, sfBlack);
    sfRenderWindow_drawSprite(wdw, bg->sprite, NULL);
    sfRenderWindow_drawSprite(wdw, duck->sprite, NULL);
    sfRenderWindow_drawText(wdw, scoreboard, NULL);
    sfRenderWindow_display(wdw);
}

void call_living_duck_anim(sfIntRect rect, sfClock *move_clock,
sfSprite *duck, int *random_y)
{
    handle_duck_move(move_clock, duck, random_y);
    sfSprite_setTextureRect(duck, rect);
}

void call_death_duck_anim(sfClock *clock, sfSprite *duck, int *living,
 sfText *score)
{
    handle_duck_death(clock, duck, living, score);
}

int main(int ac, char **av)
{
    sfRenderWindow *wdw = create_render_window(1280, 800, 32);
    sfEvent event;
    render_image_t *bg = create_render_image("./ressources/bg.png", 0.0, 0.0);
    render_image_t *duck = create_render_image("./ressources/duck.png", 0.0,
    create_random_value(0, 524));
    sfIntRect rect = create_animation();
    sfClock *clock = sfClock_create();
    sfClock *move_clock = sfClock_create();
    int random_y = create_random_value(2, 20);
    int living = 1;
    sfText *scoreboard = create_scoreboard("0");

    while (sfRenderWindow_isOpen(wdw)) {
        if (living == 1) {
            time_anim(clock, &rect);
            call_living_duck_anim(rect, move_clock, duck->sprite, &random_y);
        } else
            call_death_duck_anim(clock, duck->sprite, &living, scoreboard);
        analyse_events(wdw, event, duck->sprite, &living);
        call_draw_functions(wdw, bg, duck, scoreboard);
    }
}
