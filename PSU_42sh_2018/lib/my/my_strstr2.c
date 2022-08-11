/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** check if str1 exist in str2
*/

int my_strlen(char const *str);

int my_strstr2(char *str1, char *str2)
{
    if (my_strlen(str2) < my_strlen(str1))
        return (0);
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}
