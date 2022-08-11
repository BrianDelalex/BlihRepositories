/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for 103cipher
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_control
{
    int **key;
    int key_size;
    int **mess;
    int mess_size;
    int **crypted;
    float **invert_key;
    float **invert_crypted;
}t_control;

#endif
