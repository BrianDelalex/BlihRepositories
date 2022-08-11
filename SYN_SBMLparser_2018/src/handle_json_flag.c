/*
** EPITECH PROJECT, 2019
** handle_json_flag.c
** File description:
** handle displays for json
*/

#include "../include/my.h"

void handle_json_flag(iflag_t *iflag, char **file, char *i_name)
{
    if (iflag && iflag->comp == 1)
        display_json_comp(file, i_name);
    if (iflag && iflag->species == 1)
        display_json_species(file, i_name);
    if (iflag && iflag->react == 1)
        display_json_react(file, i_name);
}
