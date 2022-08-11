/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header for my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

/* INCLUDES */

#include <stdarg.h>

/* MY_PRINTF' S PROTOTYPES */

int find_format_and_print(char const *format, int *i, va_list *list);

#endif
