/*
** EPITECH PROJECT, 2018
** display_result.c
** File description:
** displays the results
*/

#include "struct.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display_result2(t_control *control)
{
    int ct = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < control->key_size; i++)
        for (int j = 0; j < control->key_size; j++)
            display_crypted_float(control, control->invert_key, i, j);
    printf("\nDecrypted message:\n");
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++, ct++)
            displays_message(control, i, j);
    printf("\n");
}

void display_key(t_control *control, int **tab, int i, int j)
{
    if (j < control->key_size - 1)
        printf("%d	", tab[i][j]);
    else
        printf("%d\n", tab[i][j]);
}

void display_result(t_control *control)
{
    printf("Key matrix:\n");
    for (int i = 0; i < control->key_size; i++)
        for (int j = 0; j < control->key_size; j++)
            display_key(control, control->key, i, j);
    printf("\nEncrypted message:\n");
    for (int i = 0; i < control->mess_size; i++)
        for (int j = 0; j < control->key_size; j++)
            display_encrypt(control, i, j);
}
