/*
** EPITECH PROJECT, 2018
** screensaver.c
** File description:
** screensaver
*/

#include "../include/my.h"

char *cd_home(char ***environ)
{
    int pwd = 0;
    int h = 0;
    int k = 3;

    for (; (*environ)[h] && strncp((*environ)[h], "HOME=", 4) == -1
; h++);
    for (; (*environ)[pwd] && strncp((*environ)[pwd], "PWD=", 3) == -1; pwd++);
    if ((*environ)[pwd] == NULL || (*environ)[h] == NULL)
        return ("KO");
    change_env_oldpwd(environ, pwd);
    (*environ)[pwd] = malloc(sizeof(char) * (my_strlen((*environ)[h])) + 1);
    (*environ)[pwd][0] = 'P';
    (*environ)[pwd][1] = 'W';
    (*environ)[pwd][2] = 'D';
    for (int i = 4; (*environ)[h][i]; i++, k++)
        (*environ)[pwd][k] = (*environ)[h][i];
    (*environ)[pwd][k] = '\0';
    return ("OK");
}

void change_env_oldpwd(char ***environ, int pwd)
{
    int old = 0;
    int k = 3;

    for (; (*environ)[old] && strncp((*environ)[old], "OLDPWD=", 6) == -1;
old++);
    if ((*environ)[old] == NULL)
        return;
    (*environ)[old] = malloc(sizeof(char) * 1024);
    (*environ)[old][0] = 'O';
    (*environ)[old][1] = 'L';
    (*environ)[old][2] = 'D';
    for (int i = 0; (*environ)[pwd][i] != '\0'; i++, k++)
        (*environ)[old][k] = (*environ)[pwd][i];
    (*environ)[old][k] = '\0';
}

int check_dir(char *dir)
{
    for (int i = 0; dir[i]; i++)
        if ((dir[i] == '/' && dir[i + 1] == '/') || dir[i] == ' ')
            return (84);
    return (0);
}

char *oldpwd_take_pwd(char *environ, char *tmp)
{
    int p = 3;

    environ = malloc(sizeof(char) * 1024);
    if (environ == NULL)
        return (tmp);
    environ[0] = 'O';
    environ[1] = 'L';
    environ[2] = 'D';
    for (int g = 0; tmp[g] != '\0'; g++, p++)
        environ[p] = tmp[g];
    environ[p] = '\0';
    free(tmp);
    return (environ);
}

char *oldpwd_path(char *path, char ***environ)
{
    char *tmp = malloc(sizeof(char) * 1024);
    int k = 0;
    int a = 0;
    int i = 0;

    path = malloc(sizeof(char) * 1024);
    for (; (*environ)[k] && strncp((*environ)[k], "OLDPWD=", 6) == -1; k++);
    for (; (*environ)[a] && strncp((*environ)[a], "PWD=", 3) == -1; a++);
    if (tmp == NULL || (*environ)[k] == NULL || (*environ)[a] == NULL)
        return (path);
    tmp = my_strcpy(tmp, (*environ)[a]);
    (*environ)[a] = malloc(sizeof(char) * 1024);
    for (int j = 3; (*environ)[k][j] != '\0'; j++, i++) {
        path[i] = (*environ)[k][j];
        (*environ)[a][i] = (*environ)[k][j];
    }
    path[i] = '\0';
    (*environ)[a][i] = '\0';
    (*environ)[k] = oldpwd_take_pwd((*environ)[k], tmp);
    return (path);
}
