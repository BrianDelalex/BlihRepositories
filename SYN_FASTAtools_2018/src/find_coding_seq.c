/*
** EPITECH PROJECT, 2019
** find_coding_seq.c
** File description:
** find coding seq
*/

#include "../include/my.h"

int find_end_seq(char **end, char **codons)
{
    for (int i = 1; codons[i]; i++) {
        if (is_in_tab(end, codons[i]))
            return (1);
        //if (my_strcmp(codons[i], "ATG"))
        //    return (0);
    }
    return (0);
}

char *find_coding_seq2(char *dna, char ***seqs)
{
    char *end_f[4] = {"TAA", "TAG", "TGA", NULL}, **codons, *seq = "ATG";
    int cpy = 0;

    if (dna == NULL)
        return (NULL);
    codons = separate_codon(dna, 3);
    if (!(find_end_seq(end_f, codons)))
        return (dna + 3);
    for (int i = 0; codons[i]; i++) {
        if (is_in_tab(end_f, codons[i])) {
            cpy = 0;
            *seqs = add_str_to_tab2(seq, *seqs);
            return (dna + 3);
        }
        if (cpy == 1)
            seq = my_strconcat(seq, codons[i]);
        if (my_strcmp(codons[i], "ATG"))
            cpy = 1;
    }
}

void find_coding_seq3(char *dna, char ***seq)
{
    char *next = dna;

    for (; next != NULL; )
        next = find_coding_seq2(my_strstr(next, "ATG"), seq);
}

char **find_coding_seq(char **file)
{
    char **dna = save_dna(file);
    char **rev = reverse_complement(file);
    char **seq = NULL;
    char *next;

    for (int i = 0; dna[i]; i++)
        if (dna[i][0] != '>')
            find_coding_seq3(dna[i], &seq);
    for (int i = 0; rev[i]; i++)
        if (rev[i][0] != '>')
            find_coding_seq3(rev[i], &seq);
    seq = sort_tags(seq);
    seq = sort_tags(seq);
    return(seq);
}
