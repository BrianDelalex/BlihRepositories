/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int u = 0;
    int result = 0;
    int neg = 0;
    
    while (str[i] < 48 || str[i] > 57)
        i = i + 1; 
    while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57) ) {
        if (i > 0 && str[i - 1] == 45)
            neg = 1;
        result = result * 10;
        result = result + (str[i] - '0');
        if (u >= 10)
            return (0);
        u = u + 1;
        i = i + 1;
    }
    if (neg == 1)
        result = result * (-1);
    return (result);
}
