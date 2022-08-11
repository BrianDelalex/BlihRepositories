/*
** EPITECH PROJECT, 2019
** separate_codon.c
** File description:
** separates codons
*/

#include "../include/my.h"

int my_strlen(char const *str);

char **separate_codon(char *line, int size)
{
    char *codon = malloc(sizeof(char *) * 4);
    int len = my_strlen(line) / size + 1, k = 0, j = 0;
    char **cod_tab = malloc(sizeof(char *) * len);

    if (size > my_strlen(line))
        return (NULL);
    for (int i = 0; line[i]; i++, j++) {
        if (j > size - 1) {
            codon[size] = 0;
            cod_tab[k] = my_strdup(cod_tab[k], codon);
            j = -1;
            i--;
            k++;
        } else
            codon[j] = line[i];
    }
    codon[size] = 0;
    cod_tab[k] = my_strdup(cod_tab[k], codon);
    cod_tab[len - 1] = NULL;
    return (cod_tab);
}
