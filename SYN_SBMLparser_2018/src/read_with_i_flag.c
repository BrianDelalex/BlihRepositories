/*
** EPITECH PROJECT, 2019
** read_with_i_flag.c
** File description:
** read the sbml file if the i flag is on
*/

#include "../include/my.h"

void read_with_i_flag(FILE *file, parse_t *parse)
{
    iflag_t *iflag = NULL;
    char **f_tab = read_and_return_file(file);

    if (parse->i_name != NULL)
        iflag = create_iflag(parse->i_name, f_tab);
    if (iflag && parse->json == 1)
        handle_json_flag(iflag, f_tab, parse->i_name);
    else {
        if (iflag && iflag->comp == 1)
            display_compartment_tag(iflag->file, parse->i_name);
        if (iflag && iflag->species == 1)
            display_species_tag(iflag->file, parse->i_name);
        if (iflag && iflag->react == 1)
            display_reaction_tag(iflag->file, parse->i_name, parse->e);
        if (iflag == NULL || (iflag->react == 0 && iflag->species == 0 &&
        iflag->comp == 0)) {
            display_all_product(f_tab);
        }
    }
}
