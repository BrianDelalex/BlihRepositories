/*
** EPITECH PROJECT, 2018
** my_getdigit.c
** File description:
** take a char as parameter and return the int value of this char
*/

int my_getdigit(char c)
{
    int result;

    result = c - 48;
    return (result);
}