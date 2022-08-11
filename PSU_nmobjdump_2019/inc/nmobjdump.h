/*
** EPITECH PROJECT, 2019
** nmobjdump.h
** File description:
** header for both objdump and nm
*/

#ifndef NMOBJDUMP_H_
#define NMOBJDUMP_H_

#include <sys/mman.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

void *map_file(const char *filename);
Elf64_Ehdr *get_elf_header(void *map, char *filename);
Elf64_Shdr **get_section_header_64(void *map, Elf64_Ehdr *elfHd);
Elf32_Shdr **get_section_header_32(void *map, Elf64_Ehdr *elfHd);

#endif