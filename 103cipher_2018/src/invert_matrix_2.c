/*
** EPITECH PROJECT, 2018
** invert_matrix_2.c
** File description:
** inverts a 2 2 matrix
*/

#include "struct.h"
#include <stdlib.h>

void invert_matrix_2(t_control *ctrl)
{
    int dtmg = ctrl->key[0][0] * ctrl->key[1][1] - ctrl->key[0][1]
    * ctrl->key[1][0];

    ctrl->invert_key = malloc(sizeof(float *) * ctrl->key_size);
    for (int i = 0; i < ctrl->key_size; i++)
        ctrl->invert_key[i] = malloc(sizeof(float) * ctrl->key_size);
    ctrl->invert_key[0][0] = (float) ctrl->key[1][1] / dtmg;
    ctrl->invert_key[0][1] = (float) - ctrl->key[0][1] / dtmg;
    ctrl->invert_key[1][0] = (float) - ctrl->key[1][0] / dtmg;
    ctrl->invert_key[1][1] = (float) ctrl->key[0][0] / dtmg;
}

void invert_matrix_1(t_control *ctrl)
{
    ctrl->invert_key = malloc(sizeof(float *) * 1);
    ctrl->invert_key[0] = malloc(sizeof(float) * 1);
    ctrl->invert_key[0][0] = (float) 1 / ctrl->key[0][0];
}

void multiplie_matrix_1(t_control *ctrl)
{
    for (int i = 0; i < ctrl->mess_size; i++)
        for (int j = 0; j < ctrl->key_size; j++)
            ctrl->crypted[i][j] = ctrl->mess[i][0] * ctrl->key[0][j];
}

void multiplie_invert_matrix_1(t_control *control)
{
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++) {
            control->invert_crypted[i][j] =  (control->mess[i][0] *
            control->invert_key[0][j]);
        }
}
