/*
** EPITECH PROJECT, 2018
** bsq_prime.c
** File description:
** bsq_prime
*/

#include "../../include/my.h"

void my_put_tab(char **tab)
{
    int a = 0;

    while (tab[a] != NULL) {
        my_putstr(tab[a]);
        my_putchar('\n');
        a = a + 1;
    }
    return;
}
