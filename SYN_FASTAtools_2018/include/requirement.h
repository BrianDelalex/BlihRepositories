/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header for requirement.c
*/

#ifndef REQUIREMENT_H_
#define REQUIREMENT_H_

#define IS_NON_ALPHANUMERIC(x)    ((x < 48 || x > 57) && (x < 65 || x > 90)\
&& (x < 97 || x > 122))
#define IS_CAP(x)   (x >= 65 && x <= 90)
#define IS_LOWER(x) (x >= 97 && x <= 122)

#endif
