/*
** EPITECH PROJECT, 2019
** find_amino_acids.c
** File description:
** find amino acids
*/

#include "../include/my.h"

char find_amino_acids4(char *codon)
{
    if (my_strcmp(codon, "CCT") || my_strcmp(codon, "CCC") ||
    my_strcmp(codon, "CCA") || my_strcmp(codon, "CCG"))
        return ('P');
    if (my_strcmp(codon, "CAA") || my_strcmp(codon, "CAG"))
        return ('Q');
    if (my_strcmp(codon, "CGA") || my_strcmp(codon, "CGG") ||
    my_strcmp(codon, "AGA") || my_strcmp(codon, "AGG") ||
    my_strcmp(codon, "CGT") || my_strcmp(codon, "CGC"))
        return ('R');
    if (my_strcmp(codon, "TCT") || my_strcmp(codon, "TCC") ||
    my_strcmp(codon, "TCA") || my_strcmp(codon, "TCG") ||
    my_strcmp(codon, "AGT") || my_strcmp(codon, "AGC"))
        return ('S');
    if (my_strcmp(codon, "ACT") || my_strcmp(codon, "ACC") ||
    my_strcmp(codon, "ACA") || my_strcmp(codon, "ACG"))
        return ('T');
    if (my_strcmp(codon, "GTT") || my_strcmp(codon, "GTC") ||
    my_strcmp(codon, "GTA") || my_strcmp(codon, "GTG"))
        return ('V');
    return (find_amino_acids5(codon));
}

char find_amino_acids3(char *codon)
{
    if (my_strcmp(codon, "GGT") || my_strcmp(codon, "GGC") ||
    my_strcmp(codon, "GGA") || my_strcmp(codon, "GGG"))
        return ('G');
    if (my_strcmp(codon, "CAT") || my_strcmp(codon, "CAC"))
        return ('H');
    if (my_strcmp(codon, "ATT") || my_strcmp(codon, "ATC") ||
    my_strcmp(codon, "ATA"))
        return ('I');
    if (my_strcmp(codon, "AAA") || my_strcmp(codon, "AAG"))
        return ('K');
    if (my_strcmp(codon, "TTA") || my_strcmp(codon, "TTG") ||
    my_strcmp(codon, "CTT") || my_strcmp(codon, "CTC") ||
    my_strcmp(codon, "CTA") || my_strcmp(codon, "CTG"))
        return ('L');
    if (my_strcmp(codon, "ATG"))
        return ('M');
    if (my_strcmp(codon, "AAT") || my_strcmp(codon, "AAC"))
        return ('N');
    return (find_amino_acids4(codon));
}

char *find_amino_acids2(char *codon)
{
    char *acid = malloc(sizeof(char) * (my_strlen(codon) / 3 + 1));
    char **codons = separate_codon(codon, 3);
    int i = 0;

    for (; codons[i]; i++) {
        if (codons[i][0] == 'N' || codons[i][1] == 'N' || codons[i][2] == 'N')
            acid[i] = 'X';
        if (my_strcmp(codons[i], "GAA") || my_strcmp(codons[i], "GAG"))
            acid[i] = 'E';
        if (my_strcmp(codons[i], "TTT") || my_strcmp(codons[i], "TTC"))
            acid[i] = 'F';
        if (!(acid[i]))
            acid[i] = find_amino_acids3(codons[i]);
    }
    acid[i] = 0;
    return (acid);
}

static int cmpstringp(const void *p1, const void *p2)
{
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

void find_amino_acids(char **file)
{
    char **codons = find_coding_seq(file);
    int tab_len = 0;
    char **acids;

    for (; codons[tab_len]; tab_len++);
    acids = malloc(sizeof(char *) * (tab_len + 1));
    for (int i = 0; codons[i]; i++)
        acids[i] = find_amino_acids2(codons[i]);
    qsort(acids, tab_len, sizeof(char **), cmpstringp);
    my_puttab(acids);
}
