/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

int find_exec_mode2(char **cmd_line, int *i, control_t *ctrl, char ***environ)
{
    int builtin = -1;

    if (ctrl->redirect == 5) {
        *i = *i + 2;
        return (exec_pipe(cmd_line, *i - 2));
    }
    if (ctrl->redirect == 0 || ctrl->redirect == 6 || ctrl->redirect == 7)
        builtin = is_a_builtin(cmd_line[*i], environ);
    if (builtin == -1)
        return (-1);
    if ((ctrl->redirect == 0 || ctrl->redirect == 6 || ctrl->redirect == 7)
    && builtin == 0) {
        if (cmd_line[*i + 1] && (my_strcmp(cmd_line[*i + 1], "&&") ||
        my_strcmp(cmd_line[*i + 1], "||"))) {
            *i = *i + 1;
            return (exec_bin(*environ, cmd_line[*i - 1]));
        } else
            return (exec_bin(*environ, cmd_line[*i]));
    }
    return (0);
}

int find_exec_mode(char **cmd_line, int *i, control_t *ctrl, char ***environ)
{
    if (ctrl->redirect == 1) {
        *i = *i + 2;
        return (exec_and_redirect_in_file(cmd_line, *i - 2, 0));
    }
    if (ctrl->redirect == 2) {
        *i = *i + 2;
        return (exec_and_redirect_in_file(cmd_line, *i - 2, 1));
    }
    if (ctrl->redirect == 3) {
        *i = *i + 2;
        return (exec_with_modified_input(cmd_line, *i - 2));
    }
    if (ctrl->redirect == 4) {
        *i = *i + 2;
        return (exec_buffering_bin(cmd_line, *i - 2));
    }
    return(find_exec_mode2(cmd_line, i, ctrl, environ));
}

int find_redirect(char **cmd_line, char ***environ)
{
    control_t *ctrl = set_control();
    int i = 0, size = 0;

    for (; cmd_line[size]; size++);
    for (; cmd_line[i]; i += 1) {
        if (i > 0 && cmd_line[i - 1])
            ctrl->redirect = check_redirect_char(cmd_line[i - 1]);
        if ((ctrl->rtn == 0 && ctrl->redirect == 6) ||
        (ctrl->rtn != 0 && ctrl->redirect == 7))
            i += 2;
        if (i >= size)
            return (0);
        if (cmd_line[i + 1])
            ctrl->redirect = check_redirect_char(cmd_line[i + 1]);
        else
            ctrl->redirect = 0;
        ctrl->rtn = find_exec_mode(cmd_line, &i, ctrl, environ);
        if (ctrl->rtn == -1)
            return (-1);
    }
    return (free_control(ctrl));
}

int start_command_line(char **cmds, char ***environ)
{
    char **cmd_line = NULL;
    int rtn = 0;

    for (int i = 0; cmds[i]; i++) {
        cmd_line = cut_input_to_tab(cmds[i]);
        for (int j = 0; cmd_line[j]; j++)
            cmd_line[j] = regex_space(cmd_line[j]);
        rtn = find_redirect(cmd_line, environ);
    }
    if (cmd_line != NULL)
        for (int i = 0; cmd_line[i]; i++)
            free(cmd_line[i]);
    free(cmd_line);
    return (rtn);
}

int loop_command_tab(char ***environ, char **com, char **cur_dir, size_t s)
{
    pip_red_t *pr = malloc(sizeof(pip_red_t));

    for (int k = 0x0; com[k]; k++) {
        initialisation_struct(pr);
        if (check_exit(com[k]) == 0x1)
            return (0x1);
        if (my_strstr(com[k], "|") != NULL && red(com[k], environ, pr) != 0x1)
            pipe_exec(com[k], environ, pr);
        else if (red(com[k], environ, pr) == 0x1)
            pr->pipe = 0x0;
        else if (my_strstr(com[k], "|") == NULL &&
    my_strstr(com[k], ">") == NULL && my_strstr(com[k], "<") == NULL) {
            check_command(com[k], environ, pr);
            *cur_dir = getcwd(*cur_dir, s);
            *environ = my_setenv(strconcat("setenv PWD ", *cur_dir), *environ);
            free(*cur_dir);
            *cur_dir = malloc(sizeof(char) * 1024);
        }
    }
    free_tab(com);
    return (0x0);
}
