/*
** EPITECH PROJECT, 2018
** my_int_to_str.c
** File description:
** convert an int to a str
*/

char *add_char_to_str(char c, char *str);

char *my_int_to_str(int i)
{
    char *str = "\0";
    int neg = 0;

    if (i == 0)
        return ("0\0");
    if (i < 0) {
        neg = 1;
        i = i * (-1);
    }
    while (i > 0) {
        str = add_char_to_str(i % 10 + 48, str);
        i = i / 10;
    }
    if (neg == 1)
        str = add_char_to_str('-', str);
    return (str);
}