/*
** EPITECH PROJECT, 2018
** array_1d_print_chars.c
** File description:
** print the char * content 1 char per line
*/

#include "include/my.h"

void array_1d_print_chars(char const *arr)
{
    for (int i = 0; arr[i] != 0; i++)
    {
        my_putchar(arr[i]);
        my_putchar('\n');
    }
}