/*
** EPITECH PROJECT, 2018
** check_map.c
** File description:
** check if the map is valid or not
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include <stdlib.h>

int check_char(char const * buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++) {
        switch(buffer[i]) {
        case 32:
            break;
        case '\n':
            break;
        case '#':
            break;
        case 'X':
            break;
        case 'O':
            break;
        case 'P':
            break;
        default:
            my_puterror("Invalid map\n");
            exit(84);
        }
    }
    return (0);
}

int check_map(char const *filepath)
{
    int fs = open(filepath, O_RDONLY);
    int size = 1;
    char buffer[101];

    while (size != 0) {
        size = read(fs, buffer, 100);
        buffer[size] = 0;
        check_char(buffer);
    }
    close(fs);
    return (0);
}
