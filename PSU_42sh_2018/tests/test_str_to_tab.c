/*
** EPITECH PROJECT, 2019
** test_str_to_tab
** File description:
** unit_test
*/

#include <criterion/criterion.h>
char **str_to_tab(char *str, char cut);

Test(str_to_tab, str_cuted)
{
    char *str = {"je m appel leo, bien"};
    char **tab = str_to_tab(str, ' ');

    cr_assert_str_eq(tab[0], "je");
    cr_assert_str_eq(tab[1], "m");
    cr_assert_str_eq(tab[2], "appel");
    cr_assert_str_eq(tab[3], "leo,");
    cr_assert_str_eq(tab[4], "bien");
}

Test(str_to_tab, str_NULL)
{
    char *str = {"hello"};
    char **tab = str_to_tab(str, ' ');

    cr_assert_str_eq(tab[0], "hello");
}
