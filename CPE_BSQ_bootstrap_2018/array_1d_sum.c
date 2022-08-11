/*
** EPITECH PROJECT, 2018
** array_1d_sum.c
** File description:
** returns the sum of array's ints
*/

#include "include/my.h"

int array_1d_sum(int const *arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res + arr[i];
    }
    return (res);
}