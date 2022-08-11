/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** check if str1 exist in str2
*/

#include "utils.h"
#include <stdlib.h>

char *my_strstr(char *str1, char *str2)
{
    int j = 0;

    for (int i = 0; str1[i]; i++) {
        if (str1[i] == str2[j])
            j++;
        else if (str1[i] == str2[0])
            j = 1;
        else
            j = 0;
        if (str2[j] == 0)
            return (str1 + i - (my_strlen(str2) - 1));
    }
    return (NULL);
}
