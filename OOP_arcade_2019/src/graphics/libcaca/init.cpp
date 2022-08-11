/*
** EPITECH PROJECT, 2019
** init.cpp
** File description:
** initialize all object for libcaca
*/

#include "my_libcaca.hpp"

caca_canvas_t *cv;
caca_display_t *dp = NULL;

extern "C" void init()
{
    while (!dp)
        dp = caca_create_display(NULL);
    cv = caca_get_canvas(dp);
    caca_set_display_title(dp, "Arcade");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
}