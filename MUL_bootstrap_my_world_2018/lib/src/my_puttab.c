/*
** EPITECH PROJECT, 2019
** my_puttab.c
** File description:
** displays the given char**
*/

int my_putstr(char const *str);

void my_puttab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
