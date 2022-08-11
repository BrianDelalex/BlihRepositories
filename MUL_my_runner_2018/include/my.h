/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** prototypes for my runner project
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

t_render *create_render(int width, int height, int nb_bit_pixel);
void render_window(t_render *render);
void analyse_events(t_render *render);
t_render_image *create_render_image(char const *filepath, float x, float y);
void move_rect(sfIntRect *rect, int offset, int max_value);
void create_background(t_render *render);
sfIntRect create_animation(int width, int height);
void move_background(t_render_image *bg, t_render_image *bg_b, int move,
int init);
void change_anim(sfIntRect *rect, int x_offset, int y_offset);
void handle_jump(t_render *render, int *jump_ct, float *jump_acc);
void handle_anim_rate(t_render *render, float milliseconds, float *jump_acc);
void handle_sprite_jump(t_render *render, float *jump_acc);
void move_obstacle(t_render_image *obstacle, int move);

#endif
