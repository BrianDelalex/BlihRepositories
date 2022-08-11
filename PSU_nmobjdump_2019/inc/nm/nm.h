/*
** EPITECH PROJECT, 2019
** nmobjdump.h
** File description:
** header for both objdump and nm
*/

#ifndef NM_H_
#define NM_H_

void print_section_symtab(void *map, Elf64_Ehdr *elfHdr);
char **sort_tab(char **tab);
char get_sym_type(unsigned char info, Elf64_Shdr *ref, unsigned char other);


#endif