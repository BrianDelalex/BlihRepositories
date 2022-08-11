/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** creates map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "struct.h"
#include "my.h"

t_map find_player_position(t_map map, int i, int j)
{
    if (map.map[i][j] == 'P') {
        map.player_x = j;
        map.player_y = i;
    }
    return (map);
}

int find_nb_of_box (char **map, int i, int j)
{
    int nb = 0;

    if (map[i][j] == 'X')
        nb = 1;
    return (nb);
}

t_map create_map2(t_map map)
{
    map.store_list = malloc(sizeof(t_vector *));
    map.store_list = create_vector_list(map);
    for (int i = 0; i <= map.lines; i++)
        for (int j = 0; j < map.cols; j++) {
            map = find_player_position(map, i, j);
            map.box = map.box + find_nb_of_box(map.map, i, j);
        }
    return (map);
}

int check_term(int lines, int cols)
{
    initscr();
    if (lines > LINES || cols > COLS) {
        printw("Your terminal is too small please enlarge it to play");
        refresh();
    }
    while (cols > COLS || lines > LINES) {
        sleep(10);
        refresh();
    }
    clear();
    refresh();
    endwin();
    return (0);
}

t_map create_map(char *filepath)
{
    t_map map;
    int fs = open(filepath, O_RDONLY);

    map.filepath = filepath;
    map.block = 0;
    map.box = 0;
    map.lines = find_nb_of_lines(filepath);
    map.cols = find_nb_of_cols(filepath);
    check_term(map.lines, map.cols);
    map.map = malloc(sizeof(char *) * (map.lines + 1));
    map.map[map.lines] = NULL;
    for (int i = 0; i <= map.lines; i++) {
        map.map[i] = malloc(sizeof(char) * (map.cols + 2));
        read(fs, map.map[i], map.cols + 1);
        map.map[i][map.cols + 1] = 0;
    }
    map.map[map.lines][map.cols] = 0;
    close(fs);
    map = create_map2(map);
    return (map);
}
