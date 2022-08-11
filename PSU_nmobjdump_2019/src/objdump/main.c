/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Entry point for nm
*/

#include "nmobjdump.h"
#include "objdump.h"

int main(int ac, char **av)
{
    void *map;
    Elf64_Ehdr *elfHdr;
    if (ac > 1)
        if ((map = map_file(av[1])) == NULL )
            return (64);
    elfHdr = get_elf_header(map, av[1]);
    print_header(elfHdr, av[1]);
    if (elfHdr->e_ident[4] == ELFCLASS64)
        print_sections64(map, elfHdr);
}