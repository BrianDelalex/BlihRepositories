/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** give_the_length_of_a_str
*/
int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
