/*
** EPITECH PROJECT, 2019
** get_elf_header.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"

void print_offset(uint32_t offset_st)
{
    printf(" %.4x ", offset_st);
}

void print_section_line64(unsigned char *section, int i, int j, char **str)
{
    for (int k = 0; k < 4; k++) {
        printf("%.02x", section[k + j + i]);
        if (isprint(section[k + j + i]) != 0)
            (*str)[k + j] = section[k + j + i];
        else
            (*str)[k + j] = '.';
    }
}

void print_section64(void *map, Elf64_Shdr elfShdr, char *strtb)
{
    unsigned char *section = (unsigned char *) (((uint64_t)map) \
        + elfShdr.sh_offset);
    char *str = malloc(sizeof(char) * 17);
    if (elfShdr.sh_size == 0)
        return;
    printf("Contents of section %s:\n", ((char *) &(strtb[elfShdr.sh_name])));
    for (int i = 0; i * sizeof(char) < elfShdr.sh_size; i = i + 16)
    {
        print_offset(elfShdr.sh_offset + i * sizeof(char));
            for (int j = 0; j < 16; j = j + 4) {
                if ((j + i) * sizeof(unsigned char) >= elfShdr.sh_size) {
                    printf("         ");
                    str[j] = ' ';
                    str[j + 1] = ' ';
                    str[j + 2] = ' ';
                    str[j + 3] = ' ';
                } else {
                    print_section_line64(section, i, j, &str);
                    printf(" ");
                }
            }
            printf(" %s\n", str);
    }
}

void print_sections64(void *map, Elf64_Ehdr *elfHdr)
{
    Elf64_Shdr *elfShdr = ((Elf64_Shdr*) (((uint64_t) map) + elfHdr->e_shoff));
    Elf64_Shdr shstrtabSection = ((Elf64_Shdr) elfShdr[elfHdr->e_shstrndx]);
    char *shstrtab = ((char *) (((uint64_t) map) + shstrtabSection.sh_offset));
    for (int i = 0; i < elfHdr->e_shnum; i++)
        print_section64(map, elfShdr[i], shstrtab);
}