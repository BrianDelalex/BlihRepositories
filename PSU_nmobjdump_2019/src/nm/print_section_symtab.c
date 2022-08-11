/*
** EPITECH PROJECT, 2019
** get_elf_header.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"
#include "string.h"
#include "nm.h"

#define is_not_special_section_index(c) (c != 0 && c != 0xff00 && \
        c != 0xff1f && c != 0xfff1 && c != 0xfff2 && c != 0xffff)

char **create_sym_tab(char *strtab, uint32_t entries, Elf64_Shdr *elfShdr, \
Elf64_Sym *table)
{
    int ct = 0;
    char **tab = malloc(sizeof(char *) * entries + 1);

    for (int i = 0 ; i < (int) entries; i++,  table++)
    {
        if (table->st_name == 0 || ELF64_ST_TYPE(table->st_info) == 4)
            continue;
        tab[ct] = malloc(sizeof(char) * (20 + strlen((char *) &(strtab[table->st_name]))));
            if (tab[ct] == NULL)
                continue;
        if (is_not_special_section_index(table->st_shndx)) {
            sprintf(tab[ct], "%016lx %c %s", table->st_value, get_sym_type(table->st_info, &elfShdr[table->st_shndx], table->st_other), ((char *) &(strtab[table->st_name])));
        } else
            sprintf(tab[ct], "%016lx %c %s", table->st_value, get_sym_type(table->st_info, NULL, table->st_other), ((char *) &(strtab[table->st_name])));
        if (table->st_value == 0)
            tab[ct] = memcpy((void *)tab[ct], (void *) "                ", 16);
        ct++;
    }
    tab[ct] = NULL;
    return (tab);
}

void print_section_symtab64(void *map, Elf64_Shdr *sym_table_s, \
    char *strtab, Elf64_Shdr *elfShdr)
{
    Elf64_Sym *sym_table = ((Elf64_Sym *) (((uint64_t)map) + \
    sym_table_s->sh_offset));
    uint32_t entries = sym_table_s->sh_size / sym_table_s->sh_entsize;
    char **tab = create_sym_tab(strtab, entries, elfShdr, sym_table);

    tab = sort_tab(tab);
    for (int i = 0; tab[i] != NULL; i++)
        printf("%s\n", tab[i]);
    for (int i = 0; tab[i] != NULL; i++)
        free (tab[i]);
    free (tab);
}

void print_section_symtab(void *map, Elf64_Ehdr *elfHdr)
{
    Elf64_Shdr *elfShdr = ((Elf64_Shdr*) (((uint64_t) map) + elfHdr->e_shoff));
    Elf64_Shdr shstrtabSection = ((Elf64_Shdr) elfShdr[elfHdr->e_shstrndx]);
    char *shstrtab = ((char *) (((uint64_t) map) + shstrtabSection.sh_offset));
    char *strtab;
    int i = 0;
    int j = 0;

    for (; i < elfHdr->e_shnum && strcmp(((char *) \
        &(shstrtab[elfShdr[i].sh_name])), ".symtab"); i++);
    for (; j < elfHdr->e_shnum && strcmp(((char *) \
        &(shstrtab[elfShdr[j].sh_name])), ".strtab"); j++);
    strtab = ((char *) (((uint64_t) map ) + elfShdr[j].sh_offset));
    print_section_symtab64(map, &elfShdr[i], strtab, elfShdr);
}