/*
** EPITECH PROJECT, 2019
** save_dna.c
** File description:
** saves the dna in char**
*/

#include "../include/my.h"

char **save_dna2(char **file, int len)
{
    int j = 0;
    char *want = {"AaTtGgCcNn\0"};
    char **seq = malloc(sizeof(char *) * (len * 2 + 1));

    for (int i = 0; file[i]; i++, j++) {
        if (file[i][0] == '>')
            seq[j] = file[i];
        if (file[i][0] != '>' && file[i + 1] && file[i + 1][0] != '>') {
            seq[j] = capitalize(my_strconcat(remove_unwanted_char\
            (file[i], want), remove_unwanted_char(file[i + 1], want)));
            i++;
        } else if (file[i][0] != '>' && file[i - 1] && file[i - 1][0] != '>') {
            seq[j - 1] = my_strconcat(seq[j - 1], capitalize
            (remove_unwanted_char(file[i], want)));
            j--;
        }
        if (file[i][0] != '>' && file[i - 1] && file[i - 1][0] == '>')
            seq[j] = capitalize(remove_unwanted_char(file[i], want));
    }
    seq[j] = NULL;
    return (seq);
}

char *format_seq(char **dna, int *i)
{
    char *rtn = dna[*i];

    *i = *i + 1;
    for (; dna[*i] && dna[*i][0] != '>'; *i = *i + 1)
        rtn = my_strconcat(rtn, dna[*i]);
    *i = *i - 1;
    return (rtn);
}

char **save_dna(char **file)
{
    int len = 0;
    char **dna = NULL;
    char **dna2 = NULL;

    for (int i = 0; file[i]; i++)
        if (file[i][0] == '>')
            len = len + 1;
    dna = save_dna2(file, len);
    for (int i  = 0; dna[i]; i++) {
        if (dna[i][0] == '>')
            dna2 = add_str_to_tab(dna[i], dna2);
        else
            dna2 = add_str_to_tab(format_seq(dna, &i), dna2);
    }
    return (dna2);
}
