/*
** EPITECH PROJECT, 2018
** add_char_to_str.c
** File description:
** adding the char given as parameter to the given str
*/

#include <stdlib.h>

int my_strlen(char *str);

char *add_char_to_str(char c, char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 1;
    int j = 0;

    for (; str[j]; j++ ,i++) {
        res[i] = str[j]; 
    }
    res[0] = c;
    res[i] = 0;
    return (res);
}
