/*
** EPITECH PROJECT, 2018
** find_nb_of_col.c
** File description:
** find the number of columns in the file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int find_nb_of_col(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    int i = 0;
    int j = 0;
    char buffer[1001];

    read(fs, buffer, 1000);
    buffer[1000] = 0;
    for (j = 0; buffer[j] != '\n'; j++);
    for (i = j + 1; buffer[i] != '\n' && i != 1000; i ++);
    for (; i >= 1000; i++) {
        read(fs, buffer, 1000);
        buffer[1000] = 0;
        for (i = i + 1; buffer[i] != '\n' && i != 1000; i ++);
        if (buffer[i] == '\n'){
            close(fs);
            return (i - j - 1);
        }
    }
    close(fs);
    return (i - j - 1);
}