/*
** EPITECH PROJECT, 2019
** exec_cd.c
** File description:
** runs cd function
*/

#include "minishell1.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *cut_path(char *input)
{
    char *path;
    int i = 0;
    int save_i = 0;
    int len = 0;

    for (; input[i] && input[i] != 'c'; i++);
    i = i + 2;
    for (; input[i] && input[i] == 32; i++);
    save_i = i;
    for (; input[i]; i++, len++);
    path = malloc(sizeof(char) * (len + 1));
    for (int j = 0; input[j + save_i]; j++)
        path[j] = input[j + save_i];
    path[len] = 0;
    if (path[len - 1] == '/')
        path = remove_char_from_str(path);
    return (path);
}

char *set_path(t_ctrl *ctrl, char *input)
{
    char **tab = my_str_to_tab(input, '/');
    char **tab_pwd = my_str_to_tab(ctrl->pwd, '/');
    int tab_len = 0;

    for (; tab_pwd[tab_len]; tab_len++);
    for (int i = 0; tab != NULL && tab[i]; i++) {
        if (tab[i][0] == '.' && tab[i][1] == '.') {
            tab_pwd = remove_str_to_tab(tab_pwd, tab_len - 1);
            tab = remove_str_to_tab(tab, 0);
            i--;
            tab_len--;
        } else if (tab[i][0] == '.' && tab[i][1] == 0) {
            tab = remove_str_to_tab(tab, 0);
            i--;
        } else {
            tab_pwd = add_char_to_tab(tab[i], tab_pwd);
            tab_len++;
        }
    }
    input = my_tab_to_str(tab_pwd, '/');
    return (input);
}

void go_home(char ***environ, t_ctrl *ctrl)
{
    char *home;
    int i_h = 0;
    int rtn = 0;

    for (;(*environ)[i_h] && my_strstr("HOME", (*environ)[i_h]) != 1; i_h++);
    home = malloc(sizeof(char) * (my_strlen((*environ)[i_h]) - 4));
    for (int i = 0 ; (*environ)[i_h][i + 5]; i++)
        home[i] = (*environ)[i_h][i + 5];
    home[my_strlen((*environ)[i_h]) - 5] = 0;
    exec_unsetenv(environ, "unsetenv OLDPWD");
    exec_setenv(environ, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    free(ctrl->pwd);
    ctrl->pwd = home;
    exec_unsetenv(environ, "unsetenv PWD");
    exec_setenv(environ, my_strconcat("setenv PWD ", home));
    rtn = chdir(ctrl->pwd);
    if (rtn == -1) {
        my_puterror("chdir error\n");
        exit (84);
    }
}

void change_path_directory(char ***environ, t_ctrl *ctrl, char *path)
{
    int rtn = 0;
    exec_unsetenv(environ, "unsetenv OLDPWD");
    exec_setenv(environ, my_strconcat("setenv OLDPWD ", ctrl->pwd));
    ctrl->pwd = remove_char_from_str(path);
    exec_unsetenv(environ, "unsetenv PWD");
    exec_setenv(environ, my_strconcat("setenv PWD ", ctrl->pwd));
    rtn = chdir(ctrl->pwd);
    if (rtn == -1) {
        my_puterror("chdir error\n");
        exit (84);
    }
}

void exec_cd(char ***environ, char *input, t_ctrl *ctrl)
{
    char *path;
    struct stat st;
    int rtn;

    if (my_strlen(input) > 4) {
        path = set_path(ctrl, cut_path(input));
        rtn = stat(path , &st);
        if (rtn == 0 && S_ISDIR(st.st_mode)) {
            change_path_directory(environ, ctrl, path);
        } else if (rtn == 0)
            my_putstr(my_strconcat(path, ": Not a directory.\n"));
        else
            my_putstr(my_strconcat(path, ": No such file or directory.\n"));
    } else if (my_strlen(input) == 4) {
        handle_one_char_cd_path(input, environ, ctrl);
    } else
        go_home(environ, ctrl);
}
