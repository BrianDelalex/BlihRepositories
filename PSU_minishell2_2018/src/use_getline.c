/*
** EPITECH PROJECT, 2019
** use_nextline.c
** File description:
** uses the nextline and return a char *
*/

#include <stdio.h>
#include "minishell1.h"

char *use_getline(void)
{
    char *input = NULL;
    size_t len = 0;
    int ret = 0;

    ret = getline(&input, &len, stdin);
    if (ret == -1 || ret == 0)
        return (NULL);
    if (my_strstr(input, "\n") == 1)
        return (input);
    input = remove_char_from_str(input);
    return (input);
}
