/*
** EPITECH PROJECT, 2018
** array_2d_sum.c
** File description:
** returns the sum of array's ints
*/

#include "include/my.h"

int array_2d_sum(int const **arr, int nb_rows, int nb_cols)
{
    int res = 0;

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            res = res + arr[i][j];
        }
    }
    return (res);
}