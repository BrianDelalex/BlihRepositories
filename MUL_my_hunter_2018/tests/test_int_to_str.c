/*
** EPITECH PROJECT, 2018
** test_int_to_str.c
** File description:
** test for the function my_int_to_str
*/

#include <criterion/criterion.h>

char *my_int_to_str(int i);
int my_getnbr(char const *str);

Test(my_int_to_str, return_value_is_int)
{
    int i = 100;
    char *str = "\0";

    str = my_int_to_str(i);
    cr_assert_str_eq(str, "100");
}

Test(my_getnbr, return_value_is_str)
{
    char *str = "0";

    cr_assert(my_getnbr(str) == 0);
    cr_assert_str_eq(my_int_to_str(my_getnbr(str) + 100), "100\0");
}