/*
** EPITECH PROJECT, 2019
** change_base_to_int.c
** File description:
** change the base and return int
*/

#include "../include/my.h"

int change_base_to_int(char *nb, int base)
{
    int rtn = 0;
    int len = my_strlen(nb);
    int bpow = base;

    if (len == 1)
        bpow = 1;
    for (int i = 1; i < len - 1; i++)
        bpow = bpow * base;
    for (int i = 0; nb[i]; i++) {
        rtn = rtn + ((nb[i] - 48) * bpow);
        bpow = bpow / base;
    }
    return (rtn);
}
