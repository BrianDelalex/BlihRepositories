#include "interpreter/interpreter.hpp"

void dump_handler(void)
{
    for (int i = 0; i < (int) comps->size(); i++)
    {
        (*comps)[i]->dump();
    }
}