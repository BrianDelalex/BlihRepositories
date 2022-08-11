/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header for my_lib
*/

#ifndef UTILS_H_
#define UTILS_H_

#define IS_DIGIT(x)	(x >= 48 && x <= 57)

/* UTILS' PROTOTYPES */

char *add_char_to_str(char *str, char c);
int my_strlen(char const *str);
char **add_str_to_tab(char *str, char **str_tab);
char *cut_repetitiv_char(char *str, char c);
int my_getnbr(char const *str);
int my_printf(char const *format, ...);
void my_putchar(char c);
int my_puterror(char const *str);
void my_putnbr(int i);
int my_putstr(char const *str);
void my_puttab(char **tab);
char **my_str_to_tab(char *str, char c);
int my_strcmp(char *str1, char *str2);
char *my_strconcat(char *str1, char *str2);
char *my_strdup(char *dest, char *src);
int my_strncmp(char const *str1, char const *str2, int n);
char *my_strstr(char *str1, char *str2);
char *my_tab_to_str(char **tab, char c);
char *remove_char_from_str(char *str);
char **remove_str_to_tab(char **tab, int index);
void my_putdouble(double f, int acc);
void my_putlong(long nb);
int is_binary(long n);

#endif
