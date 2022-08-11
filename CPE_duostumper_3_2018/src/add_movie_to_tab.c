/*
** EPITECH PROJECT, 2019
** add_movie_to_tab.c
** File description:
** add movie to a movie tab
*/

#include "my.h"
#include <stdlib.h>

t_movie **add_movie_to_tab(t_movie **db, t_movie *movie)
{
    t_movie **new_tab;
    int len = 0;
    int i = 0;

    if (db == NULL) {
        new_tab = malloc(sizeof(t_movie *) * 2);
        new_tab[0] = movie;
        new_tab[1] = NULL;
        return (new_tab);
    }
    for (; db[len] != NULL; len++);
    new_tab = malloc(sizeof(t_movie *) * (len + 2));
    for (; db[i]; i++)
        new_tab[i] = db[i];
    new_tab[i] = movie;
    new_tab[i + 1] = NULL;
    return (new_tab);
}
