/*
** EPITECH PROJECT, 2019
** check_if_nb.c
** File description:
** checks if all the char of a str are digit
*/

int check_if_nb(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 48 || str[i] > 57)
            return (-1);
    return (0);
}
