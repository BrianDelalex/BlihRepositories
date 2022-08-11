/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** returns 1 if the strings match
*/

int my_strlen(char const *str);

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] && str2[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
