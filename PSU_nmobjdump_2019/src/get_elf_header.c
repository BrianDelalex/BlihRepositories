/*
** EPITECH PROJECT, 2019
** get_elf_header.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"

Elf64_Ehdr *get_elf_header(void *map, char *filename)
{
    Elf64_Ehdr *elfHd;

    elfHd = (Elf64_Ehdr *) map;
    if (elfHd->e_ident[0] != 0x7f || elfHd->e_ident[1] != 'E' \
    || elfHd->e_ident[2] != 'L' || elfHd->e_ident[3] != 'F') {
        dprintf(2, "nm: %s: file format not recognized\n", filename);
        return (NULL);
    }
    return (elfHd);
}