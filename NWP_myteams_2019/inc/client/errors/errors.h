/*
** EPITECH PROJECT, 2019
** errors.h
** File description:
** errors header
*/

#ifndef CLIENT_ERRORS_H
#define CLIENT_ERRORS_H

# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

# define IS_A_DIGIT(c) (c >= 48 && c <= 57)
# define IS_C_AN_IP(c) (IS_A_DIGIT(c) || c == 46)

void print_help(void);
int is_an_ip(char *str);
int is_a_port(char *str);
int check_options(int ac, char **av);

#endif