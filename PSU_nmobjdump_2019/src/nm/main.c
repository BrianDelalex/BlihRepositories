/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Entry point for nm
*/

#include "nmobjdump.h"
#include "nm.h"

int sub_main(int ac, char **av)
{
    int exit;
    void *map;
    Elf64_Ehdr *elfHdr;

    for (int i = 1; i < ac; i++) {
        if ((map = map_file(av[i])) == NULL ) {
            exit = 84;
            dprintf(2, "nm: '%s': no such file or directory\n\n", av[i]);
        }
        if ((elfHdr = get_elf_header(map, av[i])) == NULL) {
            exit = 84;
            continue;
        }
        if (ac > 2)
            printf("\n%s:\n", av[i]);
        print_section_symtab(map, elfHdr);
    }
    return (exit);
}

int main(int ac, char **av)
{
    void *map;
    Elf64_Ehdr *elfHdr;

    if (ac < 2) {
        if ((map = map_file("a.out")) == NULL) {
            dprintf(2, "nm: 'a.out':No such file\n");
            return (84);
        }
        if ((elfHdr = get_elf_header(map, "a.out")) == NULL)
            return (84);
    }
    return (sub_main(ac, av));
}