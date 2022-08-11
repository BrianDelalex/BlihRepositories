/*
** EPITECH PROJECT, 2019
** formatting lib name
** File description:
** take of lib_arcade and .so
*/

#include <iostream>

std::string formating_lib_name(std::string lib)
{
    lib = lib.substr(lib.find_last_of("_", lib.length()) + 1, lib.length() - lib.find_last_of("_", lib.length()));
    lib = lib.substr(0, lib.find_first_of(".", 0));
    return (lib);
}

std::string formating_name_to_libName(const std::string &name)
{
    std::string lib = "lib_arcade_";
    lib.append(name);
    lib.append(".so");
    return (lib);
}