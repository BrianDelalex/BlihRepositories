/*
** EPITECH PROJECT, 2018
** create_key.c
** File description:
** creates key matrix
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>
#include "math.h"

void alloc_key_matrix(t_control *control, char *keyword)
{
    int len = my_strlen(keyword);

    control->key_size = 1;
    if (len >= 1 && len <= 16)
        for (; len > pow(control->key_size, 2); control->key_size++);
    else {
        my_puterror("Key is to heavy\n");
        exit(84);
    }
    control->key = malloc(sizeof(int *) * control->key_size);
    for (int i = 0; i < control->key_size; i++)
        control->key[i] = malloc(sizeof(int) * control->key_size);
}

void create_key(t_control *control, char *keyword)
{
    int j = 0;
    int i = 0;
    int ct = 0;
    int len = my_strlen(keyword);

    alloc_key_matrix(control, keyword);
    for (i = 0; i < control->key_size && keyword[ct]; i++) {
        j = 0;
        for (j = 0; j < control->key_size && keyword[ct]; j++, ct ++)
            control->key[i][j] = keyword[ct];
    }
    for (; i < control->key_size; i++) {
        for (; j < control->key_size; j++)
            control->key[i][j] = 0;
        j = 0;
    }
}
