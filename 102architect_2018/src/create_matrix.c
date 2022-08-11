/*
** EPITECH PROJECT, 2018
** create_matrix.c
** File description:
** creates matrix
*/

#include "struct.h"
#include "my.h"
#include <math.h>

t_vector *calcul_translate_matrix(t_vector *list, float **base)
{
    base[0][2] = list->x;
    base[1][2] = list->y;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            list->matrix[i][j] = base[i][j];
    return (list);
}

t_vector *calcul_scale_matrix(t_vector *list, float **base)
{
    base[0][0] = list->x;
    base[1][1] = list->y;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            list->matrix[i][j] = base[i][j];
    return (list);
}

t_vector *calcul_rotate_matrix(t_vector *list, float **base)
{
    base[0][0] = cos(list->x * M_PI / 180);
    base[0][1] = -sin(list->x * M_PI / 180);
    if (base[0][1] < 0.000000 && base[0][1] > -0.000001)
        base[0][1] = base[0][1] * -1;
    base[1][0] = sin(list->x * M_PI / 180);
    base[1][1] = cos(list->x * M_PI / 180);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            list->matrix[i][j] = base[i][j];
    return (list);
}

t_vector *calcul_reflect_matrix(t_vector *list, float **base)
{
    base[0][0] = cos(2 * (list->x * M_PI / 180));
    base[0][1] = sin(2 * (list->x * M_PI / 180));
    base[1][0] = sin(2 * (list->x * M_PI / 180));
    base[1][1] = -cos(2 * (list->x * M_PI / 180));
    if (base[1][1] < 0.000000 && base[1][1] > -0.000001)
        base[1][1] = base[1][1] * -1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            list->matrix[i][j] = base[i][j];
    return (list);
}

t_vector *create_matrix(t_vector *list)
{
    float **base = create_base_matrix(base);

    switch(list->transfo) {
        case 't':
            list = calcul_translate_matrix(list, base);
            break;
        case 'z':
            list = calcul_scale_matrix(list, base);
            break;
        case 'r':
            list = calcul_rotate_matrix(list, base);
            break;
        case 's':
            list = calcul_reflect_matrix(list, base);
            break;
    }
    return (list);
}
