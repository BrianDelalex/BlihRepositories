/*
** EPITECH PROJECT, 2019
** cut_input_to_tab.c
** File description:
** cut the input into a tab
*/

#include <my.h>

int is_a_separator(char *inp)
{
    if (*inp == 0)
        return (0);
    if (strncp(inp, "& ", 2) == 1)
        return (2);
    if (strncp(inp, "&& ", 3) == 1)
        return (1);
    if (strncp(inp, "| ", 2) == 1)
        return (4);
    if (strncp(inp, "|| ", 3) == 1)
        return (3);
    if (strncp(inp, "< ", 2) == 1)
        return (6);
    if (strncp(inp, "<< ", 3) == 1)
        return (5);
    if (strncp(inp, "> ", 2) == 1)
        return (8);
    if (strncp(inp, ">> ", 3) == 1)
        return (7);
    return (0);
}

int nbr_seprator(char *inp)
{
    int alloc = 0, ret = 0;

    for (; *inp; inp++)
        if (*inp == 0x20 && *(inp + 1)) {
            alloc = ((ret = is_a_separator(inp + 1)) > 0) ? alloc + 1 : alloc;
            inp += (ret % 2) + 2;
        }
    return (alloc);
}

int next_separator(char *inp)
{
    uint i = 0;

    for (; *inp && is_a_separator(inp) == 0; inp++, i++);
    return (i);
}

char *write_seprator(uint sep, char **inp)
{
    char *ret = malloc((sep % 2) + 3);
    uint i = 0;

    for (; **inp && **inp == 0x20; *inp += 1);
    sep = (sep % 2) + 2;
    for (; **inp && **inp != 0x20 && i < sep; *inp += 1, i++)
        ret[i] = **inp;
    ret[i] = 0;
    for (; **inp && **inp == 0x20; *inp += 1);
    *inp -= 1;
    return (ret);
}

char **cut_input_to_tab(char *inp)
{
    char **tab = malloc((8 * (nbr_seprator(inp) * 2)) + 0x20);
    int sep = 0, j = 0, i = 0;

    tab[i] = malloc(next_separator(inp) + 10);
    for (; *inp; inp++, j++) {
        if (*inp == 32 && *(inp + 1) && (sep = is_a_separator(inp + 1)) > 0) {
            tab[i][j] = 0;
            j = -1;
            tab[i + 1] = write_seprator(sep, &inp);
            i += 2;
            tab[i] = malloc(next_separator(inp) + 10);
            continue;
        }
        tab[i][j] = *inp;
    }
    tab[i][j] = 0;
    tab[i + 1] = NULL;
    return (tab);
}
