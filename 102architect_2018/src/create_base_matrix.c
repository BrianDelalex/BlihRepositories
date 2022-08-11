/*
** EPITECH PROJECT, 2018
** create_base_matrix.c
** File description:
** creates a base matrix
*/

#include "struct.h"
#include <stdlib.h>

float **create_base_matrix(float **base)
{
    base = malloc(sizeof(float *) * 3);
    for (int i = 0; i < 3; i = i + 1)
        base[i] = malloc(sizeof(float) * 3);
    base[0][0] = 1;
    base[0][1] = 0;
    base[0][2] = 0;
    base[1][0] = 0;
    base[1][1] = 1;
    base[1][2] = 0;
    base[2][0] = 0;
    base[2][1] = 0;
    base[2][2] = 1;
    return (base);
}
