/*
** EPITECH PROJECT, 2018
** multiplie_matrix4.c
** File description:
** multiplies 4*4 matrix
*/

#include "struct.h"
#include "my.h"

void multiplie_matrix4(t_control *control)
{
    alloc_crypted_matrix(control);
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++) {
            control->crypted[i][j] = control->mess[i][0] * control->key[0][j] +
            control->mess[i][1] * control->key[1][j] + control->mess[i][2] *
            control->key[2][j] + control->mess[i][3] * control->key[3][j];
        }
}
