/*
** EPITECH PROJECT, 2019
** create_framebuffer.c
** File description:
** creates framebuffer
*/

#include "my.h"

void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, int value)
{
    fb->pixel[(x + y * 800 + y) * 4] = value;
    fb->pixel[(x + y * 800 + y) * 4 + 3] = value;
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
