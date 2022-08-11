/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes of functions for 102architect project
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

int my_getnbr(char const *av);
t_vector *parsing(int ac, char **av);
void my_putchar(char c);
int my_putnbr(int i);
t_vector *create_matrix(t_vector *list);
float **multiplie_matrix(t_vector *list);
void display_result(float **matrix, t_vector *list, int x, int y);
t_vector *my_rev_list(t_vector *list);
float *calcul_final_pos(t_vector *tmp, int x, int y);
int handle_errors(int ac, char **av);
int my_puterror(char const *str);
int my_strlen(char *str);
char *my_int_to_str(int i);
int find_previous_flag_index(char **av, int ct);
float **create_base_matrix(float **base);

#endif
