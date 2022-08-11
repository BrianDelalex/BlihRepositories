#include "interpreter.hpp"
#include "parsing.hpp"
#include "Components.hpp"
#include "IComponent.hpp"
#include <memory>
#include "invalidLink.hpp"

std::vector<std::unique_ptr<nts::IComponent>> *comps;

int main(int ac, char **av)
{
    if (check_input(ac, av) == 84)
        return (84);
    compIO *compio = create_compIO(read_file(av[1]));
    comps = new std::vector<std::unique_ptr<nts::IComponent>>;
    if (create_inputs(comps, *(compio->i), ac, av) == 84 \
        ||  create_comps(comps, *(compio->comp)) == 84)
    {
        delete_compIO(compio);
        delete comps;
        return (84);
    }
    create_output(comps, *(compio->o));
    try
    {
        link_components(comps, *(compio->links));
    }
    catch(const invalidLink& e)
    {
        std::cerr << e.getComponent() << ":" << e.what() << std::endl;
        delete_compIO(compio);
        delete comps;
        return (84);
    }
    process(comps);
    interpreter_entry();
}
