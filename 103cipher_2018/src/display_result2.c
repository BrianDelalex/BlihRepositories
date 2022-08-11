/*
** EPITECH PROJECT, 2018
** display_result2.c
** File description:
** displays result of 103cipher
*/

#include "struct.h"
#include <stdio.h>

void displays_message(t_control *control, int i, int j)
{
    if ((int) (control->invert_crypted[i][j] + 0.9) >= 32 &&
        (int) (control->invert_crypted[i][j] + 0.9) <= 126 ||
        (int) (control->invert_crypted[i][j] + 0.9) == 10)
        printf("%c", (int) (control->invert_crypted[i][j] + 0.9));
}

void display_crypted_float(t_control *control, float **tab, int i, int j)
{
    if (j < control->key_size - 1)
        printf("%.3f	", tab[i][j]);
    else
        printf("%.3f\n", tab[i][j]);
}

void display_encrypt(t_control *control, int i, int j)
{
    if (i == control->mess_size - 1 && j == control->key_size - 1 )
        printf("%d\n", control->crypted[i][j]);
    else
        printf("%d ", control->crypted[i][j]);
}
