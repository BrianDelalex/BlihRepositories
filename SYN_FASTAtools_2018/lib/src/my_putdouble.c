/*
** EPITECH PROJECT, 2019
** my_putfloat.c
** File description:
** prints a float given in arg
*/

#include "utils.h"

void my_putdouble(double f, int acc)
{
    int nb = (int) f;
    int nb2;

    my_putnbr(nb);
    for (int i = 0; i < acc; i++) {
        nb = nb * 10;
        f = f * 10.0;
    }
    nb2 = (int) f;
    nb = nb2 - nb;
    my_putchar('.');
    my_putnbr(nb);
}
