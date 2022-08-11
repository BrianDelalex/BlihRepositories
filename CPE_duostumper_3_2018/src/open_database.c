/*
** EPITECH PROJECT, 2019
** open_database.c
** File description:
** open the database file and read 
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int my_getnbr(char const *str);
t_movie **add_movie_to_tac(t_movie **db, t_movie *movie);
char *use_getline(FILE *stream);

void create_movie4(char *gl, t_movie *movie, int *i)
{
    int len = 0;

    for (; gl[*i + len] && gl[*i + len] != ','; len++);
    movie->type = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[*i] && gl[*i] != ','; j++, *i = *i + 1)
        movie->type[j] = gl[*i];
    movie->type[len] = 0;
}

void create_movie3(char *gl, t_movie *movie, int *i)
{
    int len = 0;
    char *nb;

    for (; gl[*i + len] && gl[*i + len] != ','; len++);
    movie->director = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[*i] && gl[*i] != ','; j++, *i = *i + 1)
        movie->director[j] = gl[*i];
    movie->director[len] = 0;
    *i = *i + 1;
    len = 0;
    for (; gl[*i + len] && gl[*i + len] != ','; len++);
    nb = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[*i] && gl[*i] != ','; j++, *i = *i + 1)
        nb[j] = gl[*i];
    nb[len] = 0;
    movie->id_type = my_getnbr(nb);
    *i = *i + 1;
    create_movie4(gl, movie, i);
}

void create_movie2(char *gl, t_movie *movie, int *i)
{
    int len = 0;
    char *nb;

    for (; gl[*i + len] && gl[*i + len] != ','; len++);
    movie->synposis = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[*i] && gl[*i] != ','; j++, *i = *i + 1)
        movie->synposis[j] = gl[*i];
    movie->synposis[len] = 0;
    *i = *i + 1;
    len = 0;
    for (;gl[*i + len] && gl[*i + len] != ','; len++);
    nb = malloc(sizeof(char) * (len + 1));
    for (int j = 0 ;gl[*i] && gl[*i] != ','; j++, *i = *i + 1)
        nb[j] = gl[*i];
    nb[len] = 0;
    movie->id_director = my_getnbr(nb);
    *i = *i + 1;
    create_movie3(gl, movie, i);
}

t_movie *create_movie(char *gl)
{
    int i = 0, len = 0;
    t_movie *movie = malloc(sizeof(t_movie));
    char *nb;

    for (; gl[len] && gl[len] != ','; len++);
    nb = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[i] && gl[i] != ','; j++ ,i = i + 1)
        nb[j] = gl[i];
    nb[len] = 0;
    movie->id_movie = my_getnbr(nb);
    i = i + 1;
    len = 0;
    for (; gl[i + len] && gl[i + len] != ','; len++);
    movie->title = malloc(sizeof(char) * (len + 1));
    for (int j = 0; gl[i] && gl[i] != ','; j++, i = i + 1)
        movie->title[j] = gl[i];
    movie->title[len] = 0;
    i = i + 1;
    create_movie2(gl, movie, &i);
    return (movie);
}

t_movie **open_database(char *path)
{
    t_movie **db = NULL;
    t_movie *movie;
    FILE *stream = fopen(path, "r");
    char *getline;

    if (stream == NULL)
        return (NULL);
    while (1) {
        getline = use_getline(stream);
        if (getline == NULL)
            break;
	movie = create_movie(getline);
        db = add_movie_to_tab(db, movie);
    }
    return (db);
}
