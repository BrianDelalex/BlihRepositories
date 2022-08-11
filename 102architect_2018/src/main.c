/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for 102architect project
*/

#include "struct.h"
#include "my.h"
#include "stdlib.h"

int main(int ac, char **av)
{
    t_vector *list;
    float **matrix;
    int x = 0;
    int y = 0;

    handle_errors(ac, av);
    x = my_getnbr(av[1]);
    y = my_getnbr(av[2]);
    list = parsing(ac, av);
    matrix = multiplie_matrix(list);
    display_result(matrix, list, x, y);
    return (0);
}
