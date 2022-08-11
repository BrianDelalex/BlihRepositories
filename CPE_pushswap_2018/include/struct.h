/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for push_swap project
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_list
{
    int nb;
    struct s_list *next;
}t_list;

typedef struct s_control
{
    t_list *l_a;
    t_list *l_a_end;
    int size_l_a;
    t_list *l_b;
    int size_l_b;
    int low;
    char *display;
}t_control;

#endif
