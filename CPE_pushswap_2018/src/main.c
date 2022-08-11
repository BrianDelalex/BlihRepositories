/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for push_swap project
*/

#include "struct.h"
#include "my.h"
#include <stdlib.h>

int check_if_sorted(int ac, char **av)
{
    for (int i = 1; i + 1<= ac - 1; i++)
        if (my_getnbr(av[i]) > my_getnbr(av[i + 1]))
            return (1);
    return (0);
}

int main(int ac, char **av)
{
    t_control *control = malloc(sizeof(t_control));
    t_list *l_a;
    t_list *tmp = l_a;

    if (check_if_sorted(ac, av) == 0) {
        my_putchar('\n');
        return (0);
    }
    l_a = create_list(ac, av, control);
    control->l_a = l_a;
    control->l_b = NULL;
    control->display = malloc(sizeof(char) * 1);
    control->display[0] = '\0';
    control->size_l_b = 0;
    sorting(control);
}
