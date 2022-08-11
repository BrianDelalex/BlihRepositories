/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "utils.h"

void my_putlong(long i)
{
    if (i < 0){
        my_putchar('-');
        i = i * (-1);
    }
    if (i > 9)
        my_putlong(i / 10);
    my_putchar(i % 10 + 48);
}