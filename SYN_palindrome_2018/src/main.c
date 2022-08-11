/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function for palindrome
*/

#include "../include/my.h"

int is_a_palindrome(int pal, int base)
{
    char *str;
    char *rev;

    if (base == 10)
        str = int_to_char(pal);
    else
        str = change_base_to_char(pal, base);
    rev = my_revstr(str);
    if (my_strcmp(str, rev))
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    parse_t *parse;
    int sol = 0;

    if (handle_error(av) == 84)
        return (84);
    parse = create_parse(ac, av);
    if (parse == NULL) {
        printf("invalid argument\n");
        return (84);
    }
    if (parse->nb > 0)
        find_palindrome(parse, parse->nb);
    else if (parse->pal > 0){
        for (int i = 0; i <= parse->pal ; i++)
            sol = sol + find_palindrome(parse, i);
        if (sol == 0)
            printf("no solution\n");
    }
}
