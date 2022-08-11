/*
** EPITECH PROJECT, 2018
** test_my_printf.c
** File description:
** test for my_printf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(char *const format, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, good_output, .init=redirect_all_stdout)
{
    int res = my_printf("%x%X", 46, 46);

    cr_assert_stdout_eq_str("2e2E");
    cr_assert(res == 4);
}
