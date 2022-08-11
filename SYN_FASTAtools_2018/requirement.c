/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** my_strcapitalize
*/

#include "include/requirement.h"

char *my_strcapitalize_synthesis(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (i - 1 >= 0 && IS_NON_ALPHANUMERIC(str[i - 1]) && IS_LOWER(str[i]))
            str[i] = str[i] - 32;
        if (i == 0 && IS_LOWER(str[i]))
            str[i] = str[i] - 32;
    }
    return (str);
}
