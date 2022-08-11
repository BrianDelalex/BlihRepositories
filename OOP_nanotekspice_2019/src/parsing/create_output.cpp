/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "IComponent.hpp"
#include "Components.hpp"
#include "parsing.hpp"

void create_output(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::string> &outputName)
{
    for (int i = 0; i < (int) outputName.size(); i++)
    {
        comps->push_back(std::make_unique<nts::Output>(outputName[i]));
    }
}