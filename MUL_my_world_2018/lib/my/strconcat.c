/*
** EPITECH PROJECT, 2019
** my_strconcat.c
** File description:
** concat two str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *strconcat(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char *new_str = malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0;

    for (; s1[i]; i++)
        new_str[i] = s1[i];
    for (int j = 0; s2[j]; j++, i++)
        new_str[i] = s2[j];
    new_str[i] = 0;
    return (new_str);
}
