/*
** EPITECH PROJECT, 2018
** handle_end.c
** File description:
** handles ends
*/

#include "struct.h"
#include "stdlib.h"
#include <ncurses.h>

void end_win(t_map map)
{
    free(map.map);
    free(map.store_list);
    printf("WIN\n");
    endwin();
    exit(0);
}

void end_lose(t_map map)
{
    free(map.map);
    free(map.store_list);
    printf("LOSE\n");
    endwin();
    exit(1);
}
