/*
** EPITECH PROJECT, 2019
** handle_errors.cpp
** File description:
** handler for args errors
*/

#include "core.hpp"

void handle_errors(int ac)
{
    if (ac != 2) {
        std::cerr << "Not enough arguments - Exit" << std::endl << std::endl;
        std::cout << "Arcade:   ./arcade [Librairie]" << std::endl;
        std::cout << "Librairie: a graphics librairie located in ./lib\n";
        exit(84);
    }
}