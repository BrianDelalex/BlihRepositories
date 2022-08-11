/*
** EPITECH PROJECT, 2019
** find_palindrome.c
** File description:
** find palindrome
*/

#include "../include/my.h"

int return_sol(parse_t *p, int sol)
{
    if (p->pal == -1 && sol == 0)
        printf("no solution\n");
    return (sol);
}

void modify_char(char **str, char **rev, int nb, parse_t *p)
{
    *str = change_base_to_char(nb, p->base);
    *rev = my_revstr(*str);
}

int find_palindrome_other_base(parse_t *p, int st)
{
    char *str, *rev;
    int nb = st, sol = 0;

    for (int i = 0; i <= p->i_max; i++) {
        str = change_base_to_char(nb, p->base);
        rev = my_revstr(str);
        if (((my_strcmp(str, rev) && p->pal < 0) || (my_strcmp(str, rev) &&
        p->pal > 0 && nb == p->pal)) && i >= p->i_min) {
            printf("%d leads to %d in %d iteration(s) in base %d\n", st,
            nb, i, p->base);
            sol = 1;
            break;
        }
        modify_char(&str, &rev, nb, p);
        if ((BASE_I(str, p->base) + BASE_I(rev, p->base) ) >  4294967293) {
            return (return_sol(p, sol));
        }
        nb = BASE_I(str, p->base) + BASE_I(rev, p->base);
    }
    return (return_sol(p, sol));
}

int find_palindrome_ten_base(parse_t *p, int st)
{
    char *str, *rev;
    int nb = st, sol = 0;

    for (int i = 0; i <= p->i_max; i++) {
        str = int_to_char(nb);
        rev = my_revstr(str);
        if ( ((my_strcmp(str, rev) && p->pal < 0) || (my_strcmp(str, rev)
        && p->pal > 0 && nb == p->pal) ) && i >= p->i_min ) {
            printf("%d leads to %d in %d iteration(s) in base %d\n", st,
            nb, i, p->base);
            sol = 1;
            break;
        }
        modify_char(&str, &rev, nb, p);
        if (  ((long) atoi(str) + (long) atoi(rev)) > 4294967293
        || atoi(str) < 0 || atoi(rev) < 0)
            return (return_sol(p, sol));
        nb = atoi(str) + atoi(rev);
    }
    return (return_sol(p, sol));
}

int find_palindrome(parse_t *parse, int st)
{
    if (parse->base == 10)
        return (find_palindrome_ten_base(parse, st));
    else
        return (find_palindrome_other_base(parse, st));
}
