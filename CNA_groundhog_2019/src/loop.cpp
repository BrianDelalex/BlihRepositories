/*
** EPITECH PROJECT, 2019
** loop.cpp
** File description:
** groundhog loop
*/

#include "groundhog.hpp"

void loop(int period)
{
    std::list<float> temp;
    float ipt;
    int r = 0;
    while (1)
    {
        try
        {
            ipt = get_input();
            if (ipt == -2049 && ((int) temp.size()) < period)
            {
                std::cerr << "Not enought value - EXIT" << std::endl;
                exit(84);
            } else if (ipt == -2049) {
                std::cout << "Global tendency switched " << r << " times" << std::endl;
                exit(0);
            }
            temp.push_back(ipt);
            if (temp.size() > ((uint) (period + 1)))
                temp.pop_front();
        }
        catch(const BadInput& e)
        {
            std::cerr << e.getComponent() << ": " << e.what() << '\n';
            exit (84);
        }
        r += process(period, temp);
    }
}