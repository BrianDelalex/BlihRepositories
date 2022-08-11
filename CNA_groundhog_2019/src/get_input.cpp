/*
** EPITECH PROJECT, 2019
** get_input.cpp
** File description:
** get data on "stdin
*/

#include "parsing.hpp"
#include <limits.h>


float get_input(void)
{
    std::string input;
    float rtn;
    std::cout << "\033[1;33m";
    std::getline(std::cin, input, '\n');
    std::cout << "\033[0m";
    if (std::cin.eof())
        throw BadInput("Catched EOF - EXIT", "BadInput Error");
    if (input == "STOP" || input == "stop") {
        return (-2049);
    }
    try
    {
        rtn = std::stof(input);
    }
    catch(const std::exception& e)
    {
        throw BadInput("std::stof Error", "BadInput Error");
    }
    return (rtn);
}