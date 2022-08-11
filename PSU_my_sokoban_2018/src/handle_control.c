/*
** EPITECH PROJECT, 2018
** handle_control.c
** File description:
** handles user's input
*/

#include <ncurses.h>
#include "struct.h"
#include "my.h"

t_map handle_control(char c, t_map map)
{
    if (c == '\033') {
        getch();
        switch(getch()) {
        case 'A':
            map = check_next_pos(map, 0, -1);
            break;
        case 'B':
            map = check_next_pos(map, 0, 1);
            break;
        case 'C':
            map = check_next_pos(map, 1, 0);
            break;
        case 'D':
            map = check_next_pos(map, -1, 0);
            break;
        default:
            break;
        }
    }
    return (map);
}
