/*
** EPITECH PROJECT, 2018
** array_2d_how_many.c
** File description:
** counts the number of time number appears in the array
*/

#include "include/my.h"

int array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
    int res = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            res = res + (number == arr[i][j] ? 1 : 0);
        }
    }
    return (res);
}