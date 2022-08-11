/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes for pushswap functions
*/

#ifndef MY_H_
#define MY_H_

#include "struct.h"

int my_getnbr(char const *str);
t_list *create_list(int ac, char **av, t_control *control);
void sa(t_list *l_a, t_control *control, char c);
void pa(t_control *control);
void pb(t_control *control);
void ra(t_control *control);
void rb(t_control *control);
void rr(t_control *control);
void rra(t_control *control);
void rrb(t_control *control);
void sorting(t_control *control);
int my_putnbr(int i);
int my_putstr(char const *str);
void my_putchar(char c);
void print_list(t_list *list, char c);
char *add_char_to_char(char *src, char *target);
int my_strlen(char *str);

#endif
