/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes of BSQ project functions
*/

#include "struct.h"

int my_puterror(char const *str);
int is_square_of_size(map_t map, int row, int col, int square_size);
void my_putnbr(int i);
int my_putstr(char const *str);
void my_putchar(char c);
int find_nb_of_line(char const *filepath);
int find_nb_of_col(char const *filepath);
char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols);
square_t find_square_param(square_t pv_big, map_t map, int line, int col);
int find_biggest_square(map_t map, int row, int col);
map_t create_map(char const *filepath);
int bsq(map_t map);