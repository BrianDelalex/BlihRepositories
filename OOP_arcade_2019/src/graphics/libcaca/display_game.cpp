/*
** EPITECH PROJECT, 2019
** display_game.cpp
** File description:
** display game with libcaca
*/

#include "my_libcaca.hpp"

extern caca_canvas_t *cv;
extern caca_display_t *dp;

int convert_keycode(int key)
{
    if (key == 273)
        return (259);
    if (key == 274)
        return (258);
    if (key == 275)
        return (260);
    if (key == 276)
        return (261);
    return (key);
}

extern "C" int display_game(arcd::render *rd)
{
    caca_event_t ev;

    draw_map(rd->map);
    draw_player(rd->ply);
    draw_ennemies(rd->ennemies);
    draw_texts(rd->texts);
    caca_refresh_display(dp);
    int rtn = caca_get_event(dp, CACA_EVENT_KEY_RELEASE, &ev, 0);
    int key = 0;
    if (rtn == 1)
        key = caca_get_event_key_ch(&ev);
    return (convert_keycode(key));
}