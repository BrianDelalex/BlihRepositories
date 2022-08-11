/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    t_control *control = malloc(sizeof(t_control));

    handle_errors(ac, av);
    create_key(control, av[2]);
    if (av[3][0] == '1') {
        create_invert_key(control);
        create_message2(control, av[1]);
        multiplie_invert_matrix(control);
    } else {
        create_message(control, av[1]);
        if (control->key_size == 4)
            multiplie_matrix4(control);
        else
            multiplie_matrix(control);
    }
    if (av[3][0] == '0')
        display_result(control);
    else
        display_result2(control);
}
