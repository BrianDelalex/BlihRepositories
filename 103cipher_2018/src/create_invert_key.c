/*
** EPITECH PROJECT, 2018
** create_invert_key.c
** File description:
** creates invert key matrix
*/

#include "struct.h"
#include "stdlib.h"
#include "my.h"
#include <stdio.h>
#include <math.h>

void transpose_matrix(t_control *ctrl)
{
    int **new = malloc(sizeof(int *) * 3);

    for (int i = 0; i < 3; i++)
        new[i] = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            new[i][j] = ctrl->key[j][i];
    free(ctrl->key);
    ctrl->key = new;
}

void calcul_minor_determining(t_control *ctrl, int dtmg)
{
    float **new = malloc(sizeof(float *) * 3);
    int **key = ctrl->key;

    for (int i = 0; i < 3; i++)
        new[i] = malloc(sizeof(float) * 3);
    new[0][0] = (float) (key[1][1] * key[2][2] - key[1][2] * key[2][1]) / dtmg;
    new[0][1] = (float) -(key[1][0] * key[2][2] - key[1][2] * key[2][0]) / dtmg;
    new[0][2] = (float) (key[1][0] * key[2][1] - key[1][1] * key[2][0]) / dtmg;
    new[1][0] = (float)-(key[0][1] * key[2][2] - key[0][2] * key[2][1]) / dtmg;
    new[1][1] = (float)(key[0][0] * key[2][2] - key[0][2] * key[2][0]) / dtmg;
    new[1][2] = (float)-(key[0][0] * key[2][1] - key[0][1] * key[2][0]) / dtmg;
    new[2][0] = (float)(key[0][1] * key[1][2] - key[0][2] * key[1][1]) / dtmg;
    new[2][1] = (float)-(key[0][0] * key[1][2] - key[0][2] * key[1][0]) / dtmg;
    new[2][2] = (float)(key[0][0] * key[1][1] - key[0][1] * key[1][0]) / dtmg;
    ctrl->invert_key = new;
}

int calcul_determining(t_control *ctrl)
{
    int fact = ctrl->key[0][0] * ((ctrl->key[1][1] * ctrl->key[2][2]) -
        (ctrl->key[1][2] * ctrl->key[2][1]));

    fact = fact + ((- ctrl->key[0][1]) * ((ctrl->key[1][0] * ctrl->key[2][2]) -
        (ctrl->key[1][2] * ctrl->key[2][0])));
    fact = fact + (ctrl->key[0][2] * ((ctrl->key[1][0] * ctrl->key[2][1]) -
        (ctrl->key[1][1] * ctrl->key[2][0])));
    return (fact);
}

void invert_matrix_3(t_control *control)
{
    int dtmg = calcul_determining(control);

    transpose_matrix(control);
    calcul_minor_determining(control, dtmg);
}

void create_invert_key(t_control *control)
{
    if (control->key_size == 3)
        invert_matrix_3(control);
    else if (control->key_size < 3)
        if (control->key_size == 2)
            invert_matrix_2(control);
        else
            invert_matrix_1(control);
}
