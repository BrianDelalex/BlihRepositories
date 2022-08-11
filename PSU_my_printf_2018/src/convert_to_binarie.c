/*
** EPITECH PROJECT, 2018
** convert_to_binarie.c
** File description:
** convert an int to a binarie value
*/

#include <stdlib.h>
#include "my.h"

char *alloc_char(char *str ,int i)
{
    str = malloc(sizeof(char) * (i + 1));
    for (int j = 0; j <  i; j++)
        str[j] = '0';
    str[i] = '\0';
    return (str);
}

char *convert_to_binarie(int nb)
{   
    char *bin;
    int pw_max = 0;

    for (pw_max = 0; nb > my_power(2, pw_max); pw_max++);
    if (nb == my_power(2, pw_max))
        bin = alloc_char(bin, pw_max + 1);
    else
        bin = alloc_char(bin, pw_max);
    for (int pw = 0; nb > 0; pw++) {
        if (nb == my_power(2, pw)) {
            nb = 0;
            bin[pw_max - pw] = '1';
            return (bin);
        }
        if (nb < my_power(2, pw)) {
            nb = nb - my_power(2, pw - 1);
            bin[pw_max - pw] = '1';
            pw = 0;
        }
    }
    return (bin);
}