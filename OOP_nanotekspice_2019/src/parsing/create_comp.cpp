/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "Components.hpp"
#include "ComponentCreator.hpp"
#include "IComponent.hpp"
#include <vector>
#include <memory>

int create_comps(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::tuple<std::string, std::string>> &compName)
{
    nts::ComponentCreator creator;
    
    for (int i = 0; i < (int) compName.size(); i++)
    {
        try
        {
            comps->push_back(creator.createComponent(std::get<0>(compName[i]), std::get<1>(compName[i])));
        }
        catch(const errorCompCreation& e)
        {
            std::cerr << e.getComponent() << ": " << e.what() << '\n';
            return (84);
        }
        
    }
    return (0);
}