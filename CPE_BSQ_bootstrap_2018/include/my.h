/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes for bsq bootsrap functions
*/

void my_putchar(char c);
int my_putstr(char *str);
int fs_open_file(char const *path);
void my_putnbr(int i);
int my_strlen(char const *str);
char *mem_alloc(char *a, char *b);
int is_square_of_size(char **map, int row, int col, int square_size);
char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols);