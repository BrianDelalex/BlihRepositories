#include "interpreter/interpreter.hpp"

void input_handler(std::string name, std::string val)
{
    try {
        std::size_t set = std::stoi(val);
        if (set > 1) {
            std::cerr << "Invalid input\n";
            return;
        }
        for (int i = 0; i < (int) comps->size(); i++)
        {
            if ((*comps)[i]->getName() == name && (*comps)[i]->getType() == "input")
            {
                (*comps)[i]->setPin(1, (nts::Tristate)set);
            }
        }
    } catch (std::exception const &e) {
        std::cerr << e.what() << "\n";
    }
}