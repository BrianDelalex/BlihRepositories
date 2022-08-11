/*
** EPITECH PROJECT, 2019
** add_vector_to_vectortab.c
** File description:
** add vector to a vector tab
*/

#include "my.h"

sfSprite **add_sprite_to_spritetab(sfSprite **tab, sfSprite *vec)
{
    int size = 0;
    int i = 0;
    sfSprite **new_tab;

    if (tab != NULL)
        for (; tab[size] ; size++);
    new_tab = malloc(sizeof(sfSprite *) * (size + 2));
    if (tab != NULL) {
        for (; tab[i]; i++)
            new_tab[i] = tab[i];
        new_tab[i] = vec;
        new_tab[i + 1] = NULL;
    } else {
        new_tab[0] = vec;
        new_tab[1] = NULL;
    }
    free(tab);
    return (new_tab);
}
