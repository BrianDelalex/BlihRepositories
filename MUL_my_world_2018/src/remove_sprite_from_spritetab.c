/*
** EPITECH PROJECT, 2019
** remove_sprite_from_spritetab.c
** File description:
** removes a sprite from a sprite tab
*/

#include "my.h"

sfSprite **remove_sprite_from_spritetab(sfSprite **tab, int index)
{
    sfSprite **new_tab;
    int len = 0;
    int j = 0;

    for (; tab[len]; len = len + 1);
    if (len == 1)
        return (NULL);
    new_tab = malloc(sizeof(sfSprite *) * (len + 1));
    for (int i = 0; tab[i]; i++, j++) {
        if (i == index)
            j = j - 1;
        else
            new_tab[j] = tab[i];
    }
    new_tab[j] = 0;
    return (new_tab);
}
