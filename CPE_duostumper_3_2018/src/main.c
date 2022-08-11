/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

t_movie **open_database(char *path);

int main(int ac, char **av)
{
    t_movie **db;
    if (ac < 3)
        return (84);
    db = open_database(av[1]);
    if (db == NULL)
        return (84);
    for (int i = 0; db[i]; i++)
        printf("%d;%s;%s,%d,%s;%d,%s\n", (db[i])->id_movie, (db[i])->title, (db[i])->synposis,
        (db[i])->id_director, (db[i])->director, (db[i])->id_type, (db[i])->type);
}
