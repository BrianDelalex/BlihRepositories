/*
** EPITECH PROJECT, 2018
** str_to_tab.c
** File description:
** str_to_tab
*/

#include "../../include/my.h"

int nbr_char_str(char *input, char cut)
{
    int i = 0;
    int a = 0;

    while (input[i] != '\0') {
        if (input[i] == cut)
            a = a + 1;
        i = i + 1;
    }
    return (a);
}
