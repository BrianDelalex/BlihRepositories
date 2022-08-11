/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    int array = 0;
    int a = 0;
    int e = 0;

    if (str[array] == '-') {
        a = 1;
        array = 1;
    }
    while (str[array] >= '0' && str[array] <= '9') {
        e = e * 10 + str[array] - 48;
        array = array + 1;
    }
    if (a == 1)
        e = -e;
    return (e);
}
