/*
** EPITECH PROJECT, 2019
** test_my_str_to_tab.c
** File description:
** test my_str_to_tab function
*/

#include <criterion/criterion.h>

char **my_str_to_tab(char *str, char c);

Test(my_str_to_tab, str_is_cuted)
{
    char *str = {"hello world !"};
    char **tab = my_str_to_tab(str, 32);

    cr_assert_str_eq(tab[0], "hello");
    cr_assert_str_eq(tab[1], "world");
    cr_assert_str_eq(tab[2], "!");
}
