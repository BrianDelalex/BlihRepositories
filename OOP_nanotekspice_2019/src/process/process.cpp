/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "IComponent.hpp"
#include "Components.hpp"
#include "parsing.hpp"

void process(std::vector<std::unique_ptr<nts::IComponent>> *comps)
{
    for (int i = 0; i < (int) comps->size(); i++)
    {
        if ((*comps)[i]->getType() == "output")
        {
            (*comps)[i]->compute(1);
        }
    }
    for (int i = 0; i < (int) comps->size(); i++)
    {
        if ((*comps)[i]->getType() == "output")
        {
            (*comps)[i]->dump();
        }
    }
}