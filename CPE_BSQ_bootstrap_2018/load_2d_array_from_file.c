/*
** EPITECH PROJECT, 2018
** load_2d_array_from_file.c
** File description:
** loads a rectangle stored in a file into a 2darray
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

char **load_2d_array_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    char **res = malloc(sizeof(char *) * nb_rows + 1);
    int fs = open(filepath, O_RDONLY);
    int size = 0;

    for (int i = 0; i < nb_rows; i++) {
        res[i] = malloc(sizeof(char) * nb_cols + 1);
        size = read(fs, res[i], nb_cols);
        res[i][nb_cols] = 0;
    }
    return (res);
}
