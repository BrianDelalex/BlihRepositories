/*
** EPITECH PROJECT, 2019
** create_framebuffer.c
** File description:
** creates framebuffer
*/

#include "my.h"

void draw_rectangle(framebuffer_t *fb, sfVector2f p1, sfVector2f s, sfColor c)
{
    for (int i = 0; i < s.y; i++)
        for (int j = 0; j < s.x; j++)
            put_pixel(fb, p1.x + j, p1.y + i, c);
}

void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c)
{
    fb->pixel[(x + y * fb->width) * 4] = c.r;
    fb->pixel[(x + y * fb->width) * 4 + 1] = c.g;
    fb->pixel[(x + y * fb->width) * 4 + 2] = c.b;
    fb->pixel[(x + y * fb->width) * 4 + 3] = c.a;
}

framebuffer_t *create_framebuffer(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->pixel = malloc(height * width * 32 / 8);
    framebuffer->height = height;
    framebuffer->width = width;
    return (framebuffer);
}
