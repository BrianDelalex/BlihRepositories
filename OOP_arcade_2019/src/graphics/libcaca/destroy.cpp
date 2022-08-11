/*
** EPITECH PROJECT, 2019
** destroy.cpp
** File description:
** destroy libcaca ressources
*/

#include "my_libcaca.hpp"

extern caca_canvas_t *cv;
extern caca_display_t *dp;

extern "C" void destroy(arcd::render *rd)
{
    caca_free_display(dp);
    dp = NULL;
}