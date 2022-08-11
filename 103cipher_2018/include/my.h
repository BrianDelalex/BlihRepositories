/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes for 103cipher functions
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

int handle_errors(int ac, char **av);
int my_putstr(char const *str);
int my_puterror(char const *str);
void my_putchar(char c);
int my_strlen(char *str);
void create_key(t_control *control, char *keyword);
void create_message(t_control *control, char *message);
int multiplie_matrix(t_control *control);
void display_result(t_control *control);
void display_result2(t_control *control);
void create_invert_key(t_control *control);
int my_getdigit(char c);
void create_message2(t_control *control, char *message);
int multiplie_invert_matrix(t_control *control);
void remove_minus_before_zero(t_control *control);
void invert_matrix_2(t_control *ctrl);
void multiplie_matrix_1(t_control *ctrl);
void multiplie_invert_matrix_1(t_control *control);
void invert_matrix_1(t_control *ctrl);
void displays_message(t_control *control, int i, int j);
void display_crypted_float(t_control *control, float **tab, int i, int j);
void display_encrypt(t_control *control, int i, int j);
void alloc_crypted_matrix(t_control *control);
void multiplie_matrix4(t_control *control);

#endif
