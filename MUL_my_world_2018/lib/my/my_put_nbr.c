/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** yes
*/

#include <unistd.h>
#include <printf.h>

void my_putchar3(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int d = 0;
    int f = 0;
    int i = 20;

    if (nb < 0) {
        my_putchar3(45);
        nb = -nb;
    }
    if (nb < 10)
        my_putchar3(nb + 48);
    if (nb >= 0) {
        if (nb >= 10) {
            f = (nb % 10);
            nb = (nb - f) / 10;
            my_put_nbr(nb);
            my_putchar3(f + 48);
        }
    }
    return (nb);
}
