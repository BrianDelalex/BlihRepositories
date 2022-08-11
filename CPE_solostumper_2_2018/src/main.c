/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for anagram project
*/

#include "my.h"

int my_strlen(char const *str);

int check_char(char **av, int i, int j)
{
    if (my_strcapital(av[1][i]) == my_strcapital(av[2][j]))
        return (1);
    else
        return (0);
}

int main(int ac, char **av)
{
    int match = 0;

    if (handle_errors(ac) == 84)
        return (84);
    if (my_strlen(av[1]) != my_strlen(av[2])) {
        my_putstr("no anagrams.\n");
        return (0);
    }
    for (int i = 0; av[1][i]; i++) {
        for (int j = 0; av[2][j]; j++) {
            match = match + check_char(av, i, j);
        }
        if (match > 0)
            match = 0;
        else {
            my_putstr("no anagrams.\n");
            return (0);
        }
    }
    my_putstr("anagram!\n");
    return (0);
}
