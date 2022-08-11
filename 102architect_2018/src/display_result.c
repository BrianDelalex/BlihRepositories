/*
** EPITECH PROJECT, 2018
** display_result.c
** File description:
** displays the result of the 102architect project
*/

#include "struct.h"
#include <stdio.h>

void display_result(float **matrix, t_vector *list, int x, int y)
{
    float x2 = x * matrix[0][0] + matrix[0][1] * y + matrix[0][2];
    float y2 = x * matrix[1][0] + matrix[1][1] * y + matrix[1][2];
    printf("%.2f %.2f %.2f\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("%.2f %.2f %.2f\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("%.2f %.2f %.2f\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    printf("(%d, %d) => (%.2f, %.2f)\n", x, y, x2, y2);
}
