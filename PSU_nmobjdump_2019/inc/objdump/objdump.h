/*
** EPITECH PROJECT, 2019
** nmobjdump.h
** File description:
** header for both objdump and nm
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

void print_sections64(void *map, Elf64_Ehdr *elfHdr);
void print_header(Elf64_Ehdr *elfEhdr, char *av);

#endif