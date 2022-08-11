/*
** EPITECH PROJECT, 2019
** parsing.cpp
** File description:
** Parse programm input
*/

#include "parsing.hpp"

#define IS_DIGIT(c) (c >= 48 && c <= 57)

int parsing(int ac, char **av)
{
    int rtn;

    if (ac != 2)
        throw BadInput("Wrong argument\nUsage:\n\t./groundhog period", "BadInput Error");
    for (uint i = 0; av[1][i]; i++)
        if (!IS_DIGIT(av[1][i]))
            throw BadInput("Bad argument\n Period has to be a number", "BadInput Error");
    try
    {
        rtn = std::stoi(std::string(av[1]));
    }
    catch(const std::exception& e)
    {
        throw BadInput(e.what(), "std::stoi Error");
    }
    return (rtn);
}