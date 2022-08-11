/*
** EPITECH PROJECT, 2018
** find_nb_of_line.c
** File description:
** find the number of lines in a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int find_nb_of_line(char const *filepath)
{
    int res = 0;
    int fs = open(filepath, O_RDONLY);
    char buffer[8];

    read(fs, buffer, 7);
    buffer[7] = 0;
    for (int i = 0; buffer[i] != '\n' && buffer[i] != 0; i ++)
    {
        res = res * 10;
        res = res + (buffer[i] - 48);
    }
    close(fs);
    return (res);
}