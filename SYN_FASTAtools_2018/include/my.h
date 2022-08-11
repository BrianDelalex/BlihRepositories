/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define IS_LOWER(x) (x >= 97 && x <= 122)

#include "../lib/include/utils.h"
#include <stdlib.h>
#include <stdio.h>


/* PROTOTYPES */

char *use_getline(void);
void free_tab(char **tab);
char **get_file(void);
char *remove_unwanted_char(char *str, char *want);
void display_dna_seq(char **file);
int handle_error(int ac, char **av);
void display_rna_seq(char **file);
char **save_dna(char **file);
char **reverse_complement(char **file);
char *capitalize(char *str);
char *my_revstr(char *str);
char **find_coding_seq(char **file);
char **separate_codon(char *line, int size);
char **sort_tags(char **tags);
char **add_str_to_tab2(char *str, char **str_tab);
void find_kmer(char **file, int k);
void choose_display(int flag, int k, char **file);
int is_a_number(char *str);
void find_amino_acids(char **file);
char find_amino_acids5(char *codon);

#endif
