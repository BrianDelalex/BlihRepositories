/*
** EPITECH PROJECT, 2019
** my_strcapital.c
** File description:
** returns capital value of the given char
*/

char my_strcapital(char c)
{
    if (c >= 97 && c <= 122)
        c = c - 32;
    return (c);
}
