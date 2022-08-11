/*
** EPITECH PROJECT, 2019
** find_amino_acidsbis.c
** File description:
** find amino acids
*/

#include "../include/my.h"

char find_amino_acids5(char *codon)
{
    if (my_strcmp(codon, "TGG"))
        return ('W');
    if (my_strcmp(codon, "TGT") || my_strcmp(codon, "TGC"))
        return ('C');
    if (my_strcmp(codon, "GCT") || my_strcmp(codon, "GCC") ||
    my_strcmp(codon, "GCA") || my_strcmp(codon, "GCG"))
        return ('A');
    if (my_strcmp(codon, "GAT") || my_strcmp(codon, "GAC"))
        return ('D');
    if (my_strcmp(codon, "TAT") || my_strcmp(codon, "TAC"))
        return ('Y');
}
