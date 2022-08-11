/*
** EPITECH PROJECT, 2019
** sorting.c
** File description:
** sorts word in alphabetic order
*/

#include <stdlib.h>
#include "my.h"

char *my_strcap(char c);

void compare_str(int *index, int i, char **tab)
{
    for (int j = 0; tab[*index][j] && tab[i][j]; j = j + 1) {
        if (my_strcap(tab[*index][j]) < my_strcap(tab[i][j])) {
            break;
        } else if (my_strcap(tab[i][j]) < my_strcap(tab[*index][j])) {
            *index = i;
            break;
        }
    }
}

char *my_strcap(char c)
{
    if (c >= 97 && c <= 112)
        c = c - 32;
    return (c);
}

void sorting2(int *lower, int *index, int i, char **tab)
{
    int len1 = 0;
    int len2 = 0;

    if (my_strcap(tab[i][0]) < my_strcap(*lower)) {
        *lower = tab[i][0];
        *index = i;
    } else if (my_strcap(tab[i][0]) == my_strcap(*lower)) {
       for (;tab[i][len1]; len1 = len1 + 1);
       for (;tab[*index][len2]; len2 = len2 + 1);
       if (len1 < len2) {
           *lower = tab[i][0];
           *index = i;
       } else if (len1 == len2)
           compare_str(index, i, tab);
    }
}

char **sorting(char **tab)
{
    int word_nb = 0;
    int len;
    int index = 0;
    int lower = 200;
    char **sorted;
    int j = 0;

    for (; tab[word_nb]; word_nb = word_nb + 1);
    len = word_nb;
    sorted = malloc(sizeof(char) * (word_nb + 1));
    while (word_nb > 0) {
        for (int i = 0; tab[i]; i++) {
            sorting2(&lower, &index, i, tab);
        }
        sorted[j] = tab[index];
        tab = remove_str(tab, index);
        j = j + 1;
        word_nb = word_nb - 1;
        index = 0;
        lower = 200;
    }
    sorted[len] = 0;
    return (sorted);
}
