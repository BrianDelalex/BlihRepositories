/*
** EPITECH PROJECT, 2019
** go_root.c
** File description:
** change directory to /
*/

#include "minishell1.h"
#include <unistd.h>
#include <stdlib.h>

void go_root(char ***env, t_ctrl *ctrl)
{
    char *str = malloc(sizeof(char) * 2);
    int rtn = 0;

    str[0] = '/';
    str[1] = '\0';
    exec_unsetenv(env, "unsetenv OLDPWD");
    exec_setenv(env, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    free(ctrl->pwd);
    ctrl->pwd = str;
    exec_unsetenv(env, "unsetenv PWD");
    exec_setenv(env, my_strconcat("setenv PWD ", str));
    rtn = chdir(ctrl->pwd);
    if (rtn == -1) {
        my_puterror("chdir error\n");
        exit (84);
    }
}

void go_old_pwd(char ***env, t_ctrl *ctrl)
{
    char *old;
    int i = 0;
    int rtn = 0;

    for (; (*env)[i] && my_strstr("OLDPWD=", (*env)[i]) != 1; i++);
    old = malloc(sizeof(char) * (my_strlen((*env)[i]) - 6 ));
    for (int j = 0; (*env)[i][j + 7]; j++)
        old[j] = (*env)[i][j + 7];
    old[my_strlen((*env)[i]) - 7] = 0;
    exec_unsetenv(env, "unsetenv OLDPWD");
    exec_setenv(env, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    free(ctrl->pwd);
    ctrl->pwd = old;
    exec_unsetenv(env, "unsetenv PWD");
    exec_setenv(env, my_strconcat("setenv PWD ", old));
    rtn = chdir(ctrl->pwd);
    if (rtn == -1) {
        my_puterror("chdir error\n");
        exit (84);
    }
}

void handle_one_char_cd_path(char *input, char ***environ, t_ctrl *ctrl)
{
    if (input[3] == '~')
        go_home(environ, ctrl);
    else if (input[3] == '/')
        go_root(environ, ctrl);
    else if (input[3] == '-')
        go_old_pwd(environ, ctrl);


}
