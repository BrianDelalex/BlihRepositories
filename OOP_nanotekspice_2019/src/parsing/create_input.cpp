/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "parsing.hpp"
#include "Components.hpp"

int create_input(std::vector<std::unique_ptr<nts::IComponent>> *inputs, const std::string &name, char *str)
{
    nts::Tristate val;
    std::string arg(str);
    int nb;

    try
    {
        nb = std::stoi(arg.substr(arg.find_first_of("=", 0) + 1, arg.length()));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Error in provided input values" << std::endl;
        return (84);
    }
    if (nb < 0 || nb > 1)
    {
        std::cerr << "Input value is Unknow" << std::endl;
        return (84);
    }
    val = (nts::Tristate) nb;
    inputs->push_back(std::make_unique<nts::Input>(name, val));
    return (0);
}

int create_inputs(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::string> &iName, int ac, char **av)
{
    for (int i = 0; i < (int) iName.size(); i++)
    {
        for (int j = 2; j <= ac; j++)
        {
            if (j == ac)
            {
                std::cerr << "Value for input " << iName[i] << " hasn't been provided." << std::endl;
                return (84);
            }
            if (std::string(av[j]).substr(0, std::string(av[j]).find_first_of("=", 0)) == iName[i])
            {
                if (create_input(comps, iName[i], av[j]) == 84)
                    return (84);
                break;
            }
        }
    }
    return (0);
}