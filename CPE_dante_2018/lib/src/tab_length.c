/*
** EPITECH PROJECT, 2019
** tab_length.c
** File description:
** returns the length of the given tab
*/

int tab_length(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}
