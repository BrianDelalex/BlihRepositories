/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "parsing.hpp"

int link_components(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<link> links)
{
    for (int i = 0; i < (int) links.size(); i++)
    {
        int idx1 = 0;
        int idx2 = 0;
        for (; idx1 < (int) comps->size() && (*comps)[idx1]->getName() != links[i].comp1; idx1++);
        for (; idx2 < (int) comps->size() && (*comps)[idx2]->getName() != links[i].comp2; idx2++);
        if (idx1 >= (int) comps->size() || idx2 >= (int) comps->size()) 
            throw invalidLink("Unknow component name", "Error in .links section:");
        (*comps)[idx1]->setLink(links[i].pin1, &(*comps)[idx2], links[i].pin2);
        (*comps)[idx2]->setLink(links[i].pin2, &(*comps)[idx1], links[i].pin1);
    }
}