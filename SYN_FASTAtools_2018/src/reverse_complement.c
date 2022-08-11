/*
** EPITECH PROJECT, 2019
** reverse_complement.c
** File description:
** reverse complement
*/

#include "../include/my.h"

char *reverse_complement2(char *dna)
{
    for (int i = 0; dna[i]; i++) {
        switch (dna[i]) {
        case 'T':
            dna[i] = 'A';
            break;
        case 'A':
            dna[i] = 'T';
            break;
        case 'G':
            dna[i] = 'C';
            break;
        case 'C':
            dna[i] = 'G';
            break;
        default:
            break;
        }
    }
    return (my_revstr(dna));
}

char **reverse_complement(char **file)
{
    char **dna = save_dna(file);

    for (int i = 0; dna[i]; i++)
        if (dna[i][0] != '>')
            dna[i] = reverse_complement2(dna[i]);
    return (dna);
}
