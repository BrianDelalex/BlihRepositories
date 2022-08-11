/*
** EPITECH PROJECT, 2019
** get_elf_header.c
** File description:
** get the header of the elf file
*/

#include "nmobjdump.h"
#include "string.h"
#include "nm.h"

char get_sym_type3(unsigned char i, Elf64_Shdr *r, unsigned char other)
{
    if (ELF64_ST_BIND(i) == STB_LOCAL && r != NULL && r->sh_type == 8)
        return ('b');
    if (ELF64_ST_BIND(i) == STB_LOCAL && r != NULL && \
    (r->sh_type == 6 || r->sh_type == 15 || r->sh_type == 14))
        return ('d');
    if (ELF64_ST_BIND(i) == STB_LOCAL && r != NULL \
        && r->sh_type == 1 && r->sh_flags == 3)
        return ('d');
    if (ELF64_ST_BIND(i) == STB_LOCAL && r != NULL && r->sh_type == 1 \
        && r->sh_flags == 2)
        return ('r');
    if (ELF64_ST_BIND(i) == STB_GLOBAL && ELF64_ST_VISIBILITY(other) == 2)
        return ('D');
    if (ELF64_ST_BIND(i) == STB_GLOBAL && r != NULL && r->sh_type == 8)
        return ('B');
    if (ELF64_ST_BIND(i) == STB_GLOBAL)
        return ('R');
    return ('?');
}

char get_sym_type2(unsigned char info, Elf64_Shdr *ref, unsigned char other)
{
    if (ELF64_ST_TYPE(info) == STT_FUNC)
    {
        if (ELF64_ST_BIND(info) == STB_GLOBAL && ref == NULL)
            return ('U');
        if (ELF64_ST_BIND(info) == STB_GLOBAL && ref != NULL && \
            ref->sh_type == 1)
            return ('T');
        if (ELF64_ST_BIND(info) == STB_WEAK)
            return ('w');
        if (ELF64_ST_BIND(info) == STB_LOCAL)
            return ('t');
    }
    if (ELF64_ST_TYPE(info) == STT_OBJECT)
        return (get_sym_type3(info, ref, other));
    else
        return ('?');
}

char get_sym_type(unsigned char info, Elf64_Shdr *ref, unsigned char other)
{
    if (ELF64_ST_TYPE(info) == STT_NOTYPE) {
        if (ELF64_ST_BIND(info) == STB_GLOBAL && ref != NULL \
            && ref->sh_type == 8)
            return ('B');
        if (ELF64_ST_BIND(info) == STB_GLOBAL && ref != NULL && \
            ref->sh_type == 1)
            return ('D');
        if (ELF64_ST_BIND(info) == STB_WEAK && ref == NULL)
            return ('w');
        if (ELF64_ST_BIND(info) == STB_WEAK)
            return ('W');
        if (ELF64_ST_BIND(info) == STB_LOCAL && ref != NULL && \
            ref->sh_type == 1)
            return ('r');
        if (ELF64_ST_BIND(info) == STB_LOCAL)
            return ('d');
    }
    return (get_sym_type2(info, ref, other));
}