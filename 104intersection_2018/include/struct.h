/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct for 104intersection
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct s_vector3f
{
    float x;
    float y;
    float z;
}t_vector3;

typedef struct s_control
{
    float *pt;
    float *dir;
    float *x1;
    float *x2;
    float t1;
    float t2;
    float delta;
    int shape;
    int param;
}t_control;
#endif
