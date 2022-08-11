#include "interpreter/interpreter.hpp"

void simulate_handler(void)
{
    for (int i = 0; i < (int) comps->size(); i++)
    {
        if ((*comps)[i]->getType() == "output")
        {
            (*comps)[i]->compute(1);
        }
    }
}