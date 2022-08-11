/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** header for generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#define IS_DIGIT(x)     (x >= 48 && x <= 57)

/* INCLUDE */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "../../include/my.h"

/* BUILT-IN */

char **initialize_map(int *size);
char **initiate_perfect_map(int *size);

#endif
