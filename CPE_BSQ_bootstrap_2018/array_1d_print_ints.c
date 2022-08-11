/*
** EPITECH PROJECT, 2018
** array_1d_print_ints.c
** File description:
** print all int of an int array line by line
*/

#include "include/my.h"

void array_1d_print_ints(int const *arr, int size)
{
    for (int i = 0; i < size; i++) {
        my_putnbr(arr[i]);
        my_putchar('\n');
    }
}