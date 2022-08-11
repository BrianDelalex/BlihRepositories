/*
** EPITECH PROJECT, 2018
** sokoban.c
** File description:
** sokoban
*/

#include "../../include/my.h"

char **adj_maps(char **maps, char *buff, char **argv)
{
    int cell = 0;
    int i = 0;
    int a = 0;

    struct stat s;
    stat(argv[1], &s);
    while (buff[i] != s.st_size && buff[i] != '\0') {
        maps[cell] = malloc(sizeof(char) * s.st_size / 2);
        while (buff[i] != '\n' && buff[i] != '\0') {
            maps[cell][a] = buff[i];
            a = a + 1;
            i = i + 1;
        }
        cell = cell + 1;
        a = 0;
        i = i + 1;
    }
    free(buff);
    return (maps);
}

char **pars_file(char **argv)
{
    int fd;
    struct stat s;
    stat(argv[1], &s);
    char **maps = malloc(sizeof(char *) * s.st_size);
    char *buff = malloc(sizeof(char) * s.st_size + 1);

    fd = open(argv[1], O_RDONLY);
    read(fd, buff, s.st_size);
    close(fd);
    if (buff[1] == '\0' || buff[2] == '\0')
        return (NULL);
    maps = adj_maps(maps, buff, argv);
    return (maps);
}
