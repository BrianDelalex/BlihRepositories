/*
** EPITECH PROJECT, 2019
** check_redirect_char.c
** File description:
** check which redirect char is it
*/

int check_redirect_char(char *str)
{
    if (str[0] == '>')
        if (str[1] && str[1] == '>')
            return (5);
        else
            return (3);
    else if (str[0] == '<')
        if (str[1] && str[1] == '<')
            return (6);
        else
            return (4);
    else
        if (str[0] == '|')
            return (2);
        else if (str[0] == ';')
            return (1);
    return (0);
}
