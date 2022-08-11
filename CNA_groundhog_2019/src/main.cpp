/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** groundhog entry point
*/

#include "groundhog.hpp"

int main(int ac, char **av)
{
    int period;

    try
    {
        period = parsing(ac, av);
        if (period == 0)
        {
            std::cerr << "Period can't be 0" << std::endl;
            exit (84);
        }
    }
    catch(const BadInput& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
        return (84);
    }
    loop(period);
    return (0);
}