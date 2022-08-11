/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "../lib/include/utils.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct list_s {
    char *tag;
    char **attri;
    struct list_s *next;
    struct list_s *prev;
}list_t;

typedef struct parse_s {
    int i;
    int e;
    int json;
    char *i_name;
}parse_t;

typedef struct species_s {
    char **react;
    int **stoichio;
    int **index;
    char **reactions;
}species_t;

typedef struct comp_s {
    char *id;
    char *name;
} comp_t;

typedef struct spe_s {
    char *comp;
    char *id;
    char *name;
} spe_t;

typedef struct react_s {
    char *id;
    char *name;
    char *reversible;
    char *comp;
}react_t;

typedef struct json_s {
    comp_t *comp;
    spe_t *spe;
    react_t *react;
    char **reactiv;
    char **product;
}json_t;

typedef struct iflag_s {
    int comp;
    int species;
    int react;
    char **file;
}iflag_t;

/* BUILT-IN */

void read_sbml_file(list_t *list, FILE *file);
char *use_getline(FILE *file);
list_t *sort_in_alpha_order(list_t *list, char **tags);
list_t *create_list(int len);
void display_list(list_t *list);
parse_t *create_parse(int ac, char **av);
void read_with_i_flag(FILE *file, parse_t *parse);
iflag_t *create_iflag(char const *iname, char **file);
char *save_tag(char *ipt, int *i);
char **read_and_return_file(FILE *file);
void display_compartment_tag(char **const file, char *const i_name);
int *find_iname(char const *iname, char **xbml, int *ex);
char **sort_tags(char **tags);
int **add_int_list_to_tab(int **tab, int *add);
void display_species_tag(char **file, char const *i_name);
char *find_reaction_name(char *line);
char *find_reaction_id(char *line);
char *format_id_name(char const *iname);
char *find_tag(char *line);
char *format_species_name(char const *i_name);
void display_reaction_tag(char **file, char const *i_name, int e);
char *find_species_value(char *line);
void display_all_product(char **file);
void handle_json_flag(iflag_t *iflag, char **file, char *i_name);
void display_json_react(char **file, char *name);
char *add_stoichio(char **file, int loc);
json_t *create_json_struct(void);
react_t *load_json_reaction(char **file, char *i_name);
spe_t *load_json_species(char **file, char *i_name);
comp_t *load_json_compartment(char **file, char *i_name);
void display_json_species(char **file, char *i_name);
char *find_comp_value(char *line);
void display_json_comp(char **file, char *i_name);
char *find_reversible_value(char *line);

#endif
