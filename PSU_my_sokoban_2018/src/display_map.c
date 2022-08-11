/*
** EPITECH PROJECT, 2018
** display_map.c
** File description:
** displays map in terminal
*/

#include <ncurses.h>
#include <stdlib.h>
#include "struct.h"
#include "my.h"

int main(int ac, char **av);

void restart_sokoban(t_map map)
{
    char **av = malloc(sizeof(char *) * 2);

    av[1] = map.filepath;
    endwin();
    free(map.map);
    main(2, av);
}

void loop(t_map map)
{
    char c = '0';

    while (c != 32) {
        c = getch();
        if (c == 32) {
            restart_sokoban(map);
        }
        map = handle_control(c, map);
        clear();
        display_map(map);
    }
    endwin();
}

void display_map(t_map map)
{
    initscr();
    curs_set(0);
    noecho();
    for (int i = 0; i <= map.lines; i++) {
        printw(map.map[i]);
    }
    printw("\n");
    refresh();
    loop(map);
}
