/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

/* INCLUDE */

#include <stdarg.h>

/* LIB */

char **add_char_to_tab(char *str, char **str_tab);
char *convert_to_binarie(int nb);
char *convert_to_hexa(int nb, int min);
char *convert_to_octal(int nb);
char *cut_repetitiv_char(char *str, char c);
int my_power(int nb, int p);
int my_printf(char const *format, ...);
void my_putchar(char c);
void my_putnbr(int i);
int my_putstr(char const *str);
void my_puttab(char **tab);
char **my_str_to_tab(char *str, char c);
int my_strcmp(char *str1, char *str2);
char *my_strconcat(char *str1, char *str2);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *str);
int my_strstr(char *str1, char *str2);
char *my_tab_to_str(char **tab, char c);
char *remove_char_from_str(char *str);
char **remove_str_to_tab(char **tab, int index);
void check_and_print(va_list *list, char const *form, int *i, int *ct);
int my_non_printable(char *str);
int count_nbr_digit(int nb);
int tab_length(char **tab);
int my_puterror(char const *str);
int my_getnbr(char const *str);

#endif
