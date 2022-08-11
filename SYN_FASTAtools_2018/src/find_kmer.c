/*
** EPITECH PROJECT, 2019
** find_kmer.c
** File description:
** find kmer
*/

#include "../include/my.h"

char **merge_kmer(char **kmer, char **kmer2)
{
    if (kmer2 == NULL)
        return (NULL);
    for (int i = 0; kmer2[i]; i++)
        if (!(is_in_tab(kmer, kmer2[i])))
            kmer = add_str_to_tab(kmer2[i], kmer);
    return (kmer);
}

char *find_kmer2(char *dna, int k, char ***kmer_t)
{
    char *dna2 = dna;
    char *kmer = malloc(sizeof(char) * (k + 1));

    for (int i = 0; my_strlen(dna2) >= k && dna2; dna2 = dna + i, i++) {
        for (int j = 0; dna2[j] && j < k; j++)
            kmer[j] = dna2[j];
        kmer[k] = 0;
        if (!(is_in_tab(*kmer_t, kmer)))
            *kmer_t = add_str_to_tab2(kmer, *kmer_t);
    }

}

void find_kmer(char **file, int k)
{
    char **dna = save_dna(file);
    char **kmer = NULL;

    for (int i = 0; dna[i]; i++)
        if (dna[i][0] != '>' && my_strlen(dna[i]) >= k)
            find_kmer2(dna[i], k, &kmer);
    kmer = sort_tags(kmer);
    my_puttab(kmer);
}
