/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** function's prototypes for my_sokoban
*/

#include "struct.h"

int check_map(char const *filepath);
int my_puterror(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int find_nb_of_lines(char const *filepath);
int find_nb_of_cols(char const *filepath);
t_map create_map(char *filepath);
void display_map(t_map map);
t_map handle_control(char c, t_map map);
t_map check_next_pos(t_map map, int x, int y);
t_vector *create_vector_list(t_map map);
void end_win(t_map map);
t_map check_box(t_map map, int x, int y);
void end_lose(t_map map);
int check_term(int lines, int cols);
