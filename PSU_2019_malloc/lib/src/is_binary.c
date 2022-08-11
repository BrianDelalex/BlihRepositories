/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

int is_binary(long n)
{
    if (n > 0) {
        while (n % 2 == 0) {
            n = n / 2;
        }
        if (n == 1)
            return (1);
        else
            return (0);
    }
    return (0);
}