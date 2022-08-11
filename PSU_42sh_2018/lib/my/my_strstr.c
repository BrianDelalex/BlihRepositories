/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** yes
*/

#include <unistd.h>

char *my_strstr(char *str, char *find)
{
    int k = 0;

    for (int i = 0; str[i] && find[k]; i++) {
        if (str[i] == find[k])
            k++;
        else
            k = 0;
    }
    if (find[k] == '\0')
        return (find);
    return (NULL);
}
