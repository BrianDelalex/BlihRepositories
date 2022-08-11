/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** strut for 102architect project
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_vector
{
    int x;
    int y;
    char transfo;
    float matrix[3][3];
    struct s_vector *next;
}t_vector;

#endif