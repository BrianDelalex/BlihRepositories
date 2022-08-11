/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int check_exit(char *input)
{
    if (input == NULL)
        return (1);
    if (my_strcmp(input, "exit") == 1) {
        my_putstr("exit\n");
        return (1);
    }
    return (0);
}

char *regex_space(char *str)
{
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0, k = 0;

    for (; str[k] && (str[k] == ' ' || str[k] == '\t'); k++);
    for (int j = my_strlen(str) - 1; j > 0 &&
(str[j] == ' ' || str[j] == '\t') ; j--)
        if (str[j - 1] != ' ')
            str[j] = '\0';
    for (; str[k]; k++, i++) {
        for (; str[k] && (str[k] == ' ' || str[k] == '\t'); k++);
        if (k > 0 && (str[k - 1] == '\t' || str[k - 1] == ' ') && i > 0) {
            new[i] = ' ';
            i++;
        }
        new[i] = str[k];
    }
    new[i] = '\0';
    free(str);
    return (new);
}

char **cut_semicolon(char *input)
{
    char **tab = str_to_tab(input, ';');

    for (int i = 0x0; tab[i]; i++)
        tab[i] = regex_space(tab[i]);
    return (tab);
}

int main(void)
{
    char *input = NULL, *cur_dir = malloc(sizeof(char) * 1024);
    char **com, ***env = &environ;
    size_t size = 1024;
    int ret;

    cur_dir = getcwd(cur_dir, size);
    env = initiate_env(env, cur_dir);
    free(cur_dir);
    cur_dir = malloc(sizeof(char) * 1024);
    my_putstr("?>");
    while (check_exit(input = get_next_line(0x0)) != 0x1) {
        if (input[0x0] != '\0' && environ) {
            com = cut_semicolon(input);
            ret = start_command_line(com, env);
            free_input_ressources(input, com);
        }
        if (ret == -1)
            break;
    }
    free(cur_dir);
    return (0x0);
}
