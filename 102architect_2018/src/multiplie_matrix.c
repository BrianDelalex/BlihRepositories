/*
** EPITECH PROJECT, 2018
** multiplie_matrix.c
** File description:
** multiplies matrix
*/

#include "struct.h"
#include <stdlib.h>

float **multiplie_matrix2(t_vector *list, float **matrix)
{
    float **res = malloc(sizeof(float *) * 3);

    for (int i = 0; i < 3; i ++) {
        res[i] = malloc(sizeof(float) * 3);
        for (int j = 0; j < 3; j++)
            res[i][j] = 0;
    }
    for (int ct = 0; ct < 3; ct++)
        for (int i = 0; i < 3; i ++)
            res[0][ct] = res[0][ct] + matrix[0][i] * list->matrix[i][ct];
    for (int ct = 0; ct < 3; ct++)
        for (int i = 0; i < 3; i ++)
            res[1][ct] = res[1][ct] + matrix[1][i] * list->matrix[i][ct];
    for (int ct = 0; ct < 3; ct++)
        for (int i = 0; i < 3; i ++)
            res[2][ct] = res[2][ct] + matrix[2][i] * list->matrix[i][ct];
    return (res);
}

float **multiplie_matrix(t_vector *list)
{
    float **res = malloc(sizeof(float *) * 3);
    t_vector *cpy = list;

    for (int i = 0; i < 3; i++) {
        res[i] = malloc(sizeof(float) * 3);
        for (int j = 0; j < 3; j++ )
            res[i][j] = list->matrix[i][j];
    }
    cpy = cpy->next;

    while (cpy != NULL) {
        res = multiplie_matrix2(cpy, res);
        cpy = cpy->next;
    }
    return (res);
}
