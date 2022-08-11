/*
** EPITECH PROJECT, 2019
** str_to_tab.h
** File description:
** str_to_tab header
*/

#ifndef STR_TO_TAB_H_
#define STR_TO_TAB_H_

# include <stdlib.h>
# include <string.h>

# include "def/macro.h"

# define IS_EMPTY(x) (x == '\t' || x == '\r' || x == ' ')


char **str_to_tab(char const *str);
void free_tab(char const **tab);
int lentab(char const **tab);

#endif