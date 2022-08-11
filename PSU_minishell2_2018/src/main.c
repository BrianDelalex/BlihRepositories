/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main project for minishell1
*/

#include "minishell1.h"
#include <stdlib.h>

char **parse_input(char *input)
{
    char **tab = cut_input_to_tab(input);

    for (int i = 0; tab[i]; i++) {
        tab[i] = cut_repetitiv_char(tab[i], 32);
        tab[i] = cut_tab(tab[i]);
    }
    return (tab);
}

void choice_right_exec_mode(char **input_tab, t_ctrl *ctrl, int *i)
{
    if (ctrl->redirect == 2) {
        exec_pipe(input_tab, *i);
    } else if (ctrl->redirect == 3 || ctrl->redirect == 5)
        if (ctrl->redirect == 5)
            exec_and_redirect_in_file(input_tab, *i, 1);
        else
            exec_and_redirect_in_file(input_tab, *i, 0);
    else
        if (ctrl->redirect == 6)
            exec_buffering_bin(input_tab, *i);
        else
            exec_with_modified_input(input_tab, *i);
    *i = *i + 1;
}

void send_rigth_input(char **input_tab, t_ctrl *ctrl)
{
    int i = 0;
    for (; input_tab[i] != NULL && input_tab[i + 1] != NULL; i++) {
        ctrl->redirect = check_redirect_char(input_tab[i + 1]);
        if (ctrl->redirect != 0 && ctrl->redirect != 1)
            choice_right_exec_mode(input_tab, ctrl, &i);
        else
            find_function(ctrl, input_tab[i]);
        i = i + 1;
    }
    if (input_tab[i] != NULL && input_tab[i + 1] == NULL) {
        ctrl->redirect = 0;
        find_function(ctrl, input_tab[i]);
    }
}

int main(void)
{
    t_ctrl *ctrl = set_control();
    char *input = NULL;
    char **input_tab;

    exec_unsetenv(&environ, "unsetenv OLDPWD");
    exec_setenv(&environ, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    while (1) {
        my_putstr("?>");
        input = use_getline();
        if (input == NULL)
            exec_exit(ctrl);
        else if (my_strstr(input, "\n") == 1) {
            continue;
        } else {
            input_tab = parse_input(input);
            send_rigth_input(input_tab, ctrl);
        }
    }
    return (0);

}
