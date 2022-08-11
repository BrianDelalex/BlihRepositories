/*
** EPITECH PROJECT, 2018
** my_ls.c
** File description:
** my_ls
*/

#include "../../include/my.h"

char *long_to_char(long nbr)
{
    long keep = 0, mod = 10, alloc = 1, i = 0;
    char *str;

    if (nbr == 0)
        return ("0\0");
    for (int count = 1; count < nbr; alloc++)
        count = count * 10;
    str = malloc(sizeof(char) * (alloc + 1));
    for (; keep != nbr; i++) {
        str[i] = (nbr % mod - keep) / (mod / 10) + 48;
        keep = nbr % mod;
        mod = mod * 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
