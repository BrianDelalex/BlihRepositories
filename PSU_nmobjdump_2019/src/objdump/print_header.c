/*
** EPITECH PROJECT, 2019
** get_elf_header.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"

void print_header(Elf64_Ehdr *elfEhdr, char *av)
{
    int format;
    char *arch;
    if (elfEhdr->e_ident[4] == ELFCLASS64)
        format = 64;
    else
        format = 32;
    if (elfEhdr->e_machine == 62)
        arch = "x86_64";
    else
        arch = "i386";
    printf("flags %d\n", elfEhdr->e_flags);
    printf("%s:      file format elf%d-%s\n", av, format, arch);
    if (elfEhdr->e_machine == 62)
        printf("architecture: i386:%s, flags\n", arch);
    else
        printf("architecture: %s, flags \n", arch);
    printf("start address %#.16lx\n\n", elfEhdr->e_entry);
}