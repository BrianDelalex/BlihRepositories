/*
** EPITECH PROJECT, 2018
** mem_alloc_2d_array.c
** File description:
** allocs 2d array and returns its adress
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **alloc;
    
    alloc = malloc(sizeof(char *) * nb_rows);
    for (int i = 0; i < nb_rows; i ++)
    {
        alloc[i] = malloc(sizeof(char) * nb_cols);
    }
} 