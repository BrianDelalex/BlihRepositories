/*
** EPITECH PROJECT, 2018
** create_random_value.c
** File description:
** returns a random value in the given interval
*/

#include <time.h>
#include <stdlib.h>

int create_random_value(int min, int max)
{
    int random;

    srand(time(NULL));
    random = (rand() % (max - min + 1) + min);
    return (random);
}