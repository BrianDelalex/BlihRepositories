/*
** EPITECH PROJECT, 2018
** my_str_to_float.c
** File description:
** converts a char * into a float value
*/

#include <stdlib.h>

int my_strlen(char const *str);
int my_getnbr(char const *str);

float add_dec_to_nb(char *nb, char *dec)
{
    float res = my_getnbr(nb);
    float f_dec = my_getnbr(dec);

    for (int i = 0; i != my_strlen(dec); i++)
        f_dec = f_dec / 10;
    res = res + f_dec;
    return (res);
}

float my_str_to_float(char const *str)
{
    float res = 0.0;
    int nb_size = 0;
    int dec_size = 0;
    char *dec;
    char *nb;
    
    for (nb_size = 0; str[nb_size] != '.' && str[nb_size] != 0; nb_size++);
    if (nb_size == my_strlen(str)) {
        res = my_getnbr(str);
        return (res);
    }
    for (int i = nb_size + 1; str[i] != 0; i++, dec_size++);
    nb = malloc(sizeof(char) * (nb_size + 1));
    for (int i = 0; i < nb_size; i++)
        nb[i] = str[i];
    nb[nb_size] = 0;
    dec = malloc(sizeof(char) * (dec_size + 1));
    for (int i = 0; i < dec_size; i++)
        dec[i] = str[i + nb_size + 1];
    dec[dec_size] = 0;
    return (add_dec_to_nb(nb, dec));
}