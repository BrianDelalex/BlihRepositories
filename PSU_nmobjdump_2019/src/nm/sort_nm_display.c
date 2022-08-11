/*
** EPITECH PROJECT, 2019
** sort_nm_display.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"
#include "string.h"

char strcap(char c)
{
    if (c >= 97 && c <= 122)
        return (c - 32);
    if (c == 64)
        return (91);
    return (c);
}

int nmstrcmp(char *str1, char *str2)
{
    while (1)
    {
        if (str1[0] == '_')
            str1++;
        if (str2[0] == '_')
            str2++;
        if ((str1[0] == 0 && str2[0] != 0) || \
            (strcap(str1[0]) < strcap(str2[0])))
            return (-1);
        if ((str2[0] == 0 && str1[0] != 0) || \
            (strcap(str1[0]) > strcap(str2[0])))
            return (1);
        if (str1[0] == 0 && str2[0] == 0)
            return (0);
        str1++;
        str2++;
    }
}

void check_sort(char **tab, int *unsorted)
{
    int sta;
    int stb;

    for (int i = 0; tab[i + 1] != NULL; i++)
        {
            for (sta = 19; tab[i][sta] == '_'; sta++);
            for (stb = 19; tab[i + 1][stb] == '_'; stb++);
            if (nmstrcmp((char *) (((uint64_t)tab[i]) + sta), \
                (char *) (((uint64_t)tab[i + 1]) + stb)) > 0) {
                *unsorted = *unsorted + 1;
            }
        }
}

void sort_iteration(char ***tab)
{
    int sta, stb;
    char *swap;

    for (int i = 0; (*tab)[i + 1] != NULL; i++)
    {
        for (sta = 19; (*tab)[i][sta] == '_'; sta++);
        for (stb = 19; (*tab)[i + 1][stb] == '_'; stb++);
        if (nmstrcmp((char *) (((uint64_t)(*tab)[i]) + sta), \
            (char *) (((uint64_t)(*tab)[i + 1]) + stb)) > 0) {
            swap = (*tab)[i + 1];
            (*tab)[i + 1] = (*tab)[i];
            (*tab)[i] = swap;
        }
        if (nmstrcmp((char *) (((uint64_t)(*tab)[i]) + sta), \
            (char *) (((uint64_t)(*tab)[i + 1]) + stb)) == 0 && stb > sta)
        {
                swap = (*tab)[i + 1];
                (*tab)[i + 1] = (*tab)[i];
                (*tab)[i] = swap;
        }
    }
}

char **sort_tab(char **tab)
{
    int unsorted = 1;

    while (unsorted != 0) {
        unsorted = 0;
        sort_iteration(&tab);
        check_sort(tab, &unsorted);
    }
    return (tab);
}