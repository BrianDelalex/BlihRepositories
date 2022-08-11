/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get line from the given file descriptor
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *my_strncat(char *str, char *str2, int n)
{
    char *res;
    int len = 0;
    int len2 = 0;
    int i = 0;

    if (str != NULL)
        for (;str[len]; len++);
    for (;str2[len2]; len2++);
    if (n == 0)
        n = len2;
    res = malloc(sizeof(char) * (len + n + 1));
    if (str != NULL)
        for (; str[i]; i++)
            res[i] = str[i];
    for (int j = 0; str2[j] && j < n; i++, j++)
            res[i] = str2[j];
    res[i] = 0;
    return (res);
}

void cut_str_at_backspace(char **str, char **save, char *buff)
{
    int i = 0;
    int j = 0;
    int len = 0;

    for (; buff[i] && buff[i] != '\n'; i++);
    *str = my_strncat(*str, buff, i);
    for (int k = 0; (*str)[k]; k++)
        (*str)[k] = (*str)[k] == '\n' ? 0 : (*str)[k];
    if (buff[i] == '\n') {
        for(; buff[len]; len++);
        *save = malloc(sizeof(char) * (len - i + 1));
        for (; buff[i + 1]; i++, j++)
            (*save)[j] = buff[i + 1];
        (*save)[j] = 0;
        if (buff[i] == '\n')
            (*save)[j - 1] = 0;
    } else
        *save = NULL;
}

void check_save(char **save, char **str)
{
    char *save_cpy;
    int len = 0;

    for (; (*save)[len]; len++);
    save_cpy = malloc(sizeof(char) * (len + 1));
    for (int i = 0; (*save)[i]; i++)
        save_cpy[i] = (*save)[i];
    save_cpy[len] = 0;
    cut_str_at_backspace(str, save, save_cpy);
}

char *get_next_line(int fd)
{
    static char *save;
    static int finish = 0;
    char *str = save != NULL ? save : NULL;
    char *buff = malloc(sizeof(char) * (READ_SIZE + 1));
    int size = 0;

    if (finish == 1 && save == NULL)
        return (NULL);
    if (finish == 1)
        check_save(&save, &str);
    while (1 && finish != 1) {
        size = read(fd, buff, READ_SIZE);
        if (size < 0)
            return (NULL);
        cut_str_at_backspace(&str, &save, buff);
        if (size < READ_SIZE)
            finish = 1;
        if (save != NULL || size < READ_SIZE)
            break;
    }
    return (str);
}
