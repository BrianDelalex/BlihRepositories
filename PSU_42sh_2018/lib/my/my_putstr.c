/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** yes
*/

#include <unistd.h>

int my_putchar2(char c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar2(str[a]);
        a = a + 1;
    }
}
