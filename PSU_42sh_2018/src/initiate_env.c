/*
** EPITECH PROJECT, 2019
** initiate_env.c
** File description:
** initializa env
*/

#include "../include/my.h"

char ***initiate_env(char ***env, char *cur_dir)
{
    *env = my_setenv(strconcat("setenv PWD ", cur_dir), *env);
    *env = my_setenv(strconcat("setenv OLDPWD ", cur_dir), *env);
    return (env);
}
