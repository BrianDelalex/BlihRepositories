/*
** EPITECH PROJECT, 2019
** display_dna_seq.c
** File description:
** displays the dna sequence on stout
*/

#include "../include/my.h"

char *capitalize(char *str)
{
    for (int i = 0; str[i]; i++)
        if (IS_LOWER(str[i]))
            str[i] = str[i] - 32;
    return (str);
}

char *replace_c(char *str, char c, char t)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            str[i] = t;
    return (str);
}

void display_rna_seq(char **file)
{
    char **dna = save_dna(file);
    char *want = {"AaTtGgCcNn\0"};
    int j = 0;

    for (int i = 0; dna[i]; i++) {
        if (dna[i][0] != '>')
            dna[i] = replace_c(dna[i], 'T', 'U');
    }
    my_puttab(dna);
}

void display_dna_seq(char **file)
{
    char **dna = save_dna(file);

    my_puttab(dna);
}
