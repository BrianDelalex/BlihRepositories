/*
** EPITECH PROJECT, 2019
** create_iflag.c
** File description:
** create the iflag struct and return it
*/

#include "../include/my.h"

int find_iname2(char const *iname, char *xbml)
{
    int j = 0;
    int len = my_strlen(iname);

    for (int i = 0; xbml[i]; i++) {
        if (xbml[i] == iname[j])
            j++;
        else
            j = 0;
        if (iname[j] == 0)
            return (i - (len - 1));
    }
    return (-1);
}

int *find_iname(char const *iname, char **xbml, int *ex)
{
    int *loc;

    if (ex == NULL) {
        loc = malloc(sizeof(int) * 2);
        loc[0] = 0;
    } else {
        loc = ex;
        loc[0] = loc[0] + 1;
    }
    for (int i = loc[0]; xbml[i]; i++) {
        loc[1] = find_iname2(iname, xbml[i]);
        if (loc[1] != -1) {
            loc[0] = i;
            break;
        }
    }
    return (loc);
}

char *find_tag(char *line)
{
    int len = 1;
    char *tag;

    for (; line[len] && line[len] != 32; len++);
    tag = malloc(sizeof(char) * len);
    for (int i = 1; line[i] && line[i] != 32; i++)
        tag[i - 1] = line[i];
    tag[len - 1] = 0;
    return (tag);
}

char *format_id_name(char const *iname)
{
    char *name = malloc(sizeof(char) * (my_strlen(iname) + 6));

    if (iname != NULL) {
        name[0] = 'i';
        name[1] = 'd';
        name[2] = '=';
        name[3] = '"';
        for (int i = 0; iname[i]; i++)
            name[i + 4] = iname[i];
        name[my_strlen(iname) + 4] = '"';
        name[my_strlen(iname) + 5] = 0;
        return (name);
    }
    return (NULL);
}

iflag_t *create_iflag(char const *iname, char **file)
{
    iflag_t *iflag = malloc(sizeof(iflag_t));
    int *loc = NULL;
    char *name = malloc(sizeof(char) * (my_strlen(iname) + 6));
    char *tag;

    iflag->comp = 0;
    iflag->react = 0;
    iflag->species = 0;
    iflag->file = file;
    name = format_id_name(iname);
    loc = find_iname(name, file, NULL);
    tag = find_tag(file[loc[0]]);
    if (my_strcmp("compartment", tag) == 1)
        iflag->comp = 1;
    if (my_strcmp("reaction", tag) == 1)
        iflag->react = 1;
    if (my_strcmp("species", tag) == 1)
        iflag->species = 1;
    return (iflag);
}
