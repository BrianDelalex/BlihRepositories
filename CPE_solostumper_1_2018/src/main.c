/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for sort words
*/

#include "my.h"
#include <stdlib.h>

char **reverse_strtab(char **tab)
{
    char **new_tab;
    int len = 0;
    int i = 0;

    for (; tab[len]; len = len + 1);
    new_tab = malloc(sizeof(char *) * (len + 1));
    for (; len - 1 >= 0; i++, len--)
        new_tab[i] = tab[len - 1];
    new_tab[i] = 0;
    return (new_tab);
}

int main(int ac, char **av)
{
    char **tab;

    if (ac == 1)
        return (0);
    if (ac > 2)
        return (84);
    tab = parsing(av);
    tab = reverse_strtab(tab);
    tab = sorting(tab);
    for (int i = 0; tab[i]; i = i + 1) {
        my_putstr(tab[i]);
        my_putstr(" ");
    }
    my_putstr("\n");
}
