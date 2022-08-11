/*
** EPITECH PROJECT, 2018
** handle_errors.c
** File description:
** handles input errors
*/

#include "my.h"
#include <stdlib.h>

char check_if_nb(char *str, int ct, int ac)
{
    int i = 0;
    char c = 0;

    if (ct >= ac) {
        my_puterror("Not enought arguments\n");
        exit(84);
    }
    if (str[i] == '-')
        i = i + 1;
    for (; str[i]; i = i + 1) {
        if (str[i] < 48 || str[i] > 57) {
            my_puterror("Unexpected element at ");
            my_puterror(my_int_to_str(ct));
            my_puterror("\n");
            exit(84);
        }
    }
    return (str[1]);
}

int check_flag(char *str)
{
    if (my_strlen(str) != 2) {
        my_puterror("Unknow flag\n");
        exit(84);
    }
    if (str[0] != 45) {
        my_puterror("Unknow flag\n");
        exit(84);
    }
    switch (str[1]) {
        case 't':
        case 'z':
        case 'r':
        case 's':
            break;
        default:
            my_puterror("Unknow flag\n");
            exit(84);
            break;
    }
}

int find_flag(char **av, int i)
{
    int ct = 0;

    if (av[i][ct] == '-')
        ct = ct + 1;
    switch (av[i][ct]) {
        case 't':
        case 's':
        case 'r':
        case 'z':
            return (1);
        default:
            break;
    }
    if (av[i][ct] >= 48 && av[i][ct] <= 57)
        return (0);
    my_puterror("Unexpected element at ");
    my_puterror(my_int_to_str(i));
    my_puterror("\n");
    exit(84);
}

int check_transform_arg(char **av, int i, int ac, char c)
{
    if ((c == 't' || c == 'z') && (i + 1) < ac) {
        check_if_nb(av[i], i, ac);
        check_if_nb(av[i + 1], i, ac);
        i = i + 2;
    } else if ((c == 'r' || c == 's') && i < ac){
        check_if_nb(av[i], i, ac);
        i = i + 1;
    } else {
        my_puterror("Not enought arguments\n");
        exit(84);
    }
    return (i);
}

int handle_errors(int ac, char **av)
{
    int i = 3;
    int flag = 1;
    char c = 0;

    if (ac < 4) {
        my_puterror("Too few arguments\n");
        exit(84);
    }
    check_if_nb(av[1], 1, ac);
    check_if_nb(av[2], 2, ac);
    while (i < ac) {
        if (flag == 1) {
            c = check_flag(av[i]);
            i = i + 1;
        }
        i = check_transform_arg(av, i, ac, c);
        if (i >= ac)
            break;
        flag = find_flag(av, i);
    }
    return (0);
}
