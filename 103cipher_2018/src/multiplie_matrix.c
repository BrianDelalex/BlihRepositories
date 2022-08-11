/*
** EPITECH PROJECT, 2018
** multiplie_matrix.c
** File description:
** multiplies key matrix and message matrix
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

void alloc_crypted_matrix(t_control *control)
{
    control->crypted = malloc(sizeof(int *) * control->mess_size);
    for (int i = 0; i < control->mess_size; i++)
        control->crypted[i] = malloc(sizeof(int) * control->key_size);
}

void multiplie_matrix_2(t_control *ctrl)
{
    for (int i = 0; i < ctrl->mess_size; i++)
        for (int j = 0; j < ctrl->key_size; j++) {
            ctrl->crypted[i][j] = ctrl->mess[i][0] * ctrl->key[0][j] +
            ctrl->mess[i][1] * ctrl->key[1][j];
        }
}

int multiplie_matrix(t_control *control)
{
    alloc_crypted_matrix(control);
    if (control->key_size == 2) {
        multiplie_matrix_2(control);
        return (0);
    } else if (control->key_size == 1) {
        multiplie_matrix_1(control);
        return (0);
    }
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++) {
            control->crypted[i][j] = control->mess[i][0] * control->key[0][j] +
            control->mess[i][1] * control->key[1][j] + control->mess[i][2] *
            control->key[2][j];
        }
}

void multiplie_invert_matrix_2(t_control *ctrl)
{
    for (int i = 0; i < ctrl->mess_size; i++)
        for (int j = 0; j < ctrl->key_size; j++) {
            ctrl->invert_crypted[i][j] =  (ctrl->mess[i][0] *
            ctrl->invert_key[0][j] + ctrl->mess[i][1] *
            ctrl->invert_key[1][j]);
        }
}

int multiplie_invert_matrix(t_control *control)
{
    control->invert_crypted = malloc(sizeof(float *) * control->mess_size);
    for (int i = 0; i < control->mess_size; i++)
        control->invert_crypted[i] = malloc(sizeof(float) * control->key_size);
    if (control->key_size == 2) {
        multiplie_invert_matrix_2(control);
        return (0);
    } else if (control->key_size == 1) {
        multiplie_invert_matrix_1(control);
        return (0);
    }
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++) {
            control->invert_crypted[i][j] = (control->mess[i][0] *
            control->invert_key[0][j] + control->mess[i][1] *
            control->invert_key[1][j] + control->mess[i][2] *
            control->invert_key[2][j]);
        }
}
