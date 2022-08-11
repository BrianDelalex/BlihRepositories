/*
** EPITECH PROJECT, 2019
** my_strncmp.c
** File description:
** compare the n first char in str1 and str2
*/

int my_strncmp(char const *str1, char const *str2, int n)
{
    for (int i = 0; str1[i] && str2[i] && i < n; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
