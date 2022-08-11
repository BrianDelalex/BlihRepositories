/*
** EPITECH PROJECT, 2019
** choose_display.c
** File description:
** choose display
*/

#include "../include/my.h"

void choose_display(int flags, int k, char **file)
{
    if (flags == 4)
        find_kmer(file, k);
    if (flags == 1)
        display_dna_seq(file);
    if (flags == 2)
        display_rna_seq(file);
    if (flags == 3)
        my_puttab(reverse_complement(file));
    if (flags == 5)
        my_puttab(find_coding_seq(file));
    if (flags == 6)
        find_amino_acids(file);
}
