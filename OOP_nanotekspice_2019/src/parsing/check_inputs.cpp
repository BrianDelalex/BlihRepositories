/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>

int check_input(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Not enought argument." << std::endl;
        return (84);
    }
    return (0);
}