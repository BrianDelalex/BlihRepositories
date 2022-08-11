/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes of my_hunter's functions
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include "struct.h"

sfRenderWindow *create_render_window(int width, int height, int nb_bit_pixel);
render_image_t *create_render_image(char const *filepath, float x, float y);
void analyse_events(sfRenderWindow *wdw, sfEvent event,
sfSprite *duck, int *living);
void close_window(sfRenderWindow *wdw, sfEvent event);
void manage_mouse_click(sfMouseButtonEvent event, sfSprite *duck, int *living);
sfIntRect create_animation(void);
void time_anim(sfClock *clock, sfIntRect *rect);
void my_putchar(char c);
int my_putnbr(int i);
int my_putstr(char const *str);
void handle_duck_move(sfClock *clock, sfSprite *duck, int *random_y);
void handle_duck_death(sfClock *clock ,sfSprite *duck, int *living,
sfText *score);
int create_random_value(int min, int max);
sfText *create_scoreboard(char *str);
char *my_int_to_str(int i);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *str);
void limit_framerate(sfClock *framerate);

#endif