#include "interpreter/interpreter.hpp"
#include <string.h>

bool sortMyComponent(std::unique_ptr <nts::IComponent> &x, std::unique_ptr <nts::IComponent> &y)
{
    std::string xstring = x->getName();
    std::string ystring = y->getName();
    if (strcmp(xstring.c_str(), ystring.c_str()) < 0)
        return (true);
    return (false);
}

void display_handler(void)
{
    std::vector<std::unique_ptr<nts::IComponent>> *sorted;
    std::sort(comps->begin(), comps->end(), sortMyComponent);
    for (int i = 0; i < (int) comps->size(); i++)
    {
        if ((*comps)[i]->getType() == "output")
        {
            (*comps)[i]->dump();
        }
    }
}