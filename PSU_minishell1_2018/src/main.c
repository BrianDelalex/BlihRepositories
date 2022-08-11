/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main project for minishell1
*/

#include "minishell1.h"
#include <stdlib.h>

int main(void)
{
    t_ctrl *ctrl = set_control();
    char *input = NULL;

    exec_unsetenv(&environ, "unsetenv OLDPWD");
    exec_setenv(&environ, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    while (1) {
        my_putstr("?>");
        input = use_getline();
        if (input != NULL) {
            input = cut_repetitiv_char(input, 32);
            input = cut_tab(input);
            find_function(ctrl, input);
        } else
            exec_exit(ctrl);
    }
    return (0);
}
