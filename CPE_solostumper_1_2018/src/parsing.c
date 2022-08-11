/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** parses sort word input
*/

#include <stdlib.h>

int count_nb_of_word(char **av)
{
    int nb = 1;

    for (int i = 0; av[1][i]; i = i + 1) {
        if ((av[1][i] == 32 && av[1][i + 1] != 32)|| (av[1][i] == '\\' && av[1][i + 1] == 't'))
            nb = nb + 1;
    }
    return (nb);
}

char *get_word(char **av, int start, int len)
{
    char *word = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (;av[1][start] && i < len; i++, start++) {
        word[i] = av[1][start];
    }
    word[i] = 0;
    return (word);
}

char **parsing(char **av)
{
    int word_nb = count_nb_of_word(av);
    char **tab = malloc(sizeof(char *) * (word_nb + 1));
    int len = 0;
    int i = 0;
    int start = 0;

    for (; av[1][i]; i = i + 1) {
        if (av[1][i] == 32 && av[1][i + 1] == 32);
        else if (av[1][i] == 32 || (av[1][i] == '\\' && av[1][i + 1] == 't')) {
            tab[word_nb - 1] = get_word(av, start, len);
            start = i + 1;
            len = 0;
            word_nb = word_nb - 1;
        } else
            len = len + 1;
    }
    tab[word_nb - 1] = get_word(av, i - len, len);
    return (tab);
}
