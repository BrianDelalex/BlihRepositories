/*
** EPITECH PROJECT, 2018
** stdarg.c
** File description:
** unit test for stdarg function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sum_stdarg, return_correct_when_i_is_zero)
{
    int ret = sum_stdarg(0, 3, 23, 7, -16);

    cr_assert_eq(ret, 14);
}

Test(sum_stdarg, return_correct_when_i_is_one)
{
    int ret = sum_stdarg(1, 5, "hi", "iam", "8", "test", "lol");

    cr_assert_eq(ret, 13);
}

Test(disp_stdarg, good_output, .init=redirect_all_stdout)
{
    disp_stdarg("csiis", 'X', "hi", 10, -3, "plop");
    cr_assert_stdout_eq_str("X\nhi\n10\n-3\nplop\n");
}