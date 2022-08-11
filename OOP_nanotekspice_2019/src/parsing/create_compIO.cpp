/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "parsing.hpp"
#include "errorInFile.hpp"
#include <string.h>

void delete_compIO(compIO *compio)
{
    if (compio != nullptr)
    {
        if (compio->i != nullptr)
            delete compio->i;
        if (compio->o != nullptr)
            delete compio->o;
        if (compio->clk != nullptr)
            delete compio->clk;
        if (compio->tr != nullptr)
            delete compio->tr;
        if (compio->fls != nullptr)
            delete compio->fls;
        if (compio->comp != nullptr)
            delete compio->comp;
        delete compio;
    }
}

compIO *create_compIO(const std::vector<std::string> &nts)
{
    compIO *compio = new compIO;
    memset(compio, 0, sizeof(compIO));
    try
    {
        read_chipsets(compio, nts);
        read_links(compio, nts);

    } catch (const errorInFile &e)
    {
        std::cerr << e.getComponent() << ":" << e.what() << std::endl;
        delete_compIO(compio);
        return (nullptr);
    }

    // std::cout << "INPUT: " << std::endl;
    // for (int i = 0; compio->i != nullptr && i < compio->i->size(); i++)
    //     std::cout << (*compio->i)[i] << std::endl;
    // std::cout << "OUTPUT: " << std::endl;
    // for (int i = 0; compio->o != nullptr && i < compio->o->size(); i++)
    //     std::cout << (*compio->o)[i] << std::endl;
    // std::cout << "COMPONENTS:" << std::endl;
    // for (int i = 0; compio->comp != nullptr && i < compio->comp->size(); i++)
    //     std::cout << std::get<0>((*compio->comp)[i]) << " " << std::get<1>((*compio->comp)[i]) << std::endl;
    // std::cout << "CLOCK:" << std::endl;
    // for (int i = 0; compio->clk != nullptr && i < compio->clk->size(); i++)
    //     std::cout << (*compio->clk)[i] << std::endl;
    // std::cout << "FALSE" << std::endl;
    // for (int i = 0; compio->fls != nullptr && i < compio->fls->size(); i++)
    //     std::cout << (*compio->fls)[i] << std::endl;
    // std::cout << "TRUE" << std::endl;
    // for (int i = 0; compio->tr != nullptr && i < compio->tr->size(); i++)
    //     std::cout << (*compio->tr)[i] << std::endl;
    // std::cout << "LINKS:" << std::endl;
    // for (int i = 0;compio->links != nullptr && i < compio->links->size(); i++)
    // {
        // std::cout << "comp1: " << (*compio->links)[i].comp1 << " ";
        // std::cout << "pin1: " << (*compio->links)[i].pin1 << " ";
        // std::cout << "comp2: " << (*compio->links)[i].comp2 << " ";
        // std::cout << "pin2: " << (*compio->links)[i].pin2 << std::endl;
    // }
    return (compio);
}