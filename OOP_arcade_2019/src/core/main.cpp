/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <dlfcn.h>
#include "core.hpp"

int main(int ac, char **av)
{
    handle_errors(ac);
    init(av[1]);
}