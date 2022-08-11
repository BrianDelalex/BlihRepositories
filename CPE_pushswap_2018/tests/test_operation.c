/*
** EPITECH PROJECT, 2018
** test_operation.c
** File description:
** tests operation for push_swap
*/

#include <criterion/criterion.h>
#include "struct.h"
#include <stdlib.h>

t_list *create_list(int ac, char **av);
char *my_int_to_str(int i);
void pa(t_control *control);

Test(pa, return_value_are_swaped)
{
    t_list *l_a;
    t_list *l_b;
    t_control *control = malloc(sizeof(t_control));
    char **array = malloc(sizeof(char *) * 5);
    char **array2 = malloc(sizeof(char *) * 5);

    for (int i = 0; i < 5; i++) {
        array[i] = malloc(sizeof(char) * 2);
        array[i] = my_int_to_str(i);
        array2[i] = malloc(sizeof(char) * 2);
        array2[i] = my_int_to_str(i + 5);
    }
    l_a = create_list(5, array);
    //l_b = create_list(5, array2);
    control->l_a = malloc(sizeof(t_list));
    control->l_a = l_a;
    control->l_b = malloc(sizeof(t_list));
    control->l_b = l_b;
    pb(control);
    cr_assert_eq(control->l_b->nb, 1);
}
