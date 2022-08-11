/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** prototypes for libmy.a
*/

#include <stdarg.h>

int my_strlen(char *str);
int my_putnbr(int i);
void my_putchar(char c);
int my_putstr(char const *str);
int my_power(int nb, int pw);
char *convert_to_binarie(int nb);
char *convert_to_octal(int nb);
char *my_strcpy(char *src);
char *convert_to_hexa(int nb, int min);
int my_non_printable(char *str);
int count_nbr_digit(int nb);
void check_and_print(va_list *list, char const *form, int *i, int *ct);
void check_and_print2(va_list *list, char const *form, int *i, int *ct);
void check_and_print3(va_list *list, char const *form, int *i, int *ct);
