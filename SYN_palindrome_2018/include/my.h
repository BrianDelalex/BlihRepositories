/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "../lib/include/utils.h"
#include <stdlib.h>
#include <stdio.h>

#define BASE_I(x, y)     (change_base_to_int(x, y))

/* STRUCT */

typedef struct parse_s {
    int nb;
    int pal;
    int base;
    int i_min;
    int i_max;
} parse_t;

/* BUILT-IN */

parse_t *create_parse(int ac, char **av);
int change_base_to_int(char *nb, int base);
char *change_base_to_char(int nb, int base);
int find_palindrome(parse_t *parse, int st);
char *int_to_char(int nb);
char *my_revstr(char *str);
int find_palindrome_ten_base(parse_t *p, int st);
int handle_error(char **av);
int is_a_palindrome(int pal, int base);

#endif
