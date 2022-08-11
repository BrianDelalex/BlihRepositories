/*
** EPITECH PROJECT, 2019
** add_char_to_str.c
** File description:
** add a char to a str
*/

#include <stdlib.h>
#include <utils.h>

char *add_char_to_str(char *str, char c)
{
    char *new;
    int len;

    if (str == NULL) {
        new = malloc(sizeof(char) * 2);
        if (new == NULL)
            return (NULL);
        new[0] = c;
        new[1] = 0;
        return (new);
    }
    len = my_strlen(str);
    new = malloc(sizeof(char) * (len + 2));
    if (new == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    new[len] = c;
    new[len + 1] = 0;
    return (new);
}
