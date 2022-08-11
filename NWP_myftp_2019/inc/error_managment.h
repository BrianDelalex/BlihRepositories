/*
** EPITECH PROJECT, 2019
** error_managment.h
** File description:
** errors handling header
*/

#ifndef ERROR_MANAGMENT_H_
#define ERROR_MANAGMENT_H_

#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_ftp.h"

void display_usage(void);
binInfo_t *parsing(int ac, char **av);
binInfo_t *check_dir(char **av, binInfo_t *infos);
void *parsing_error(const char *msg);

#endif