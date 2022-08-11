/*
** EPITECH PROJECT, 2019
** ComponentCreator.cpp
** File description:
** 
*/

#include "ComponentCreator.hpp"

namespace nts
{

    ComponentCreator::ComponentCreator()
    {
    }

    ComponentCreator::~ComponentCreator() {}


    std::unique_ptr<IComponent> ComponentCreator::createComponent(const std::string &type, const std::string &value)
    {
        std::string types[14] = {"4001", "4008", "4011", "4013", "4017", "4030", \
                    "4040", "4069", "4071", "4081", "4094", "4514", "4801", "2716"};
        std::unique_ptr<IComponent> (ComponentCreator::*funcs[14])(const std::string &value) const = { \
        &ComponentCreator::create4001, &ComponentCreator::create4008, &ComponentCreator::create4011, &ComponentCreator::create4013, &ComponentCreator::create4017, &ComponentCreator::create4030, &ComponentCreator::create4040, \
        &ComponentCreator::create4069, &ComponentCreator::create4071, &ComponentCreator::create4081, &ComponentCreator::create4094, &ComponentCreator::create4514, &ComponentCreator::create4801, &ComponentCreator::create2716};

        for (int i = 0; i < 14; i++) {
            if (types[i] == type)
            {
                return ((this->*funcs[i])(value));
            }
        }
        throw errorCompCreation("Unknow component type.", "Error while creating component");
    }

    std::unique_ptr<IComponent> ComponentCreator::create4001(const std::string &value) const noexcept
    {
        std::unique_ptr<IComponent> ptr = std::make_unique<Comp4001>(value);
        return (ptr);
    }
    std::unique_ptr<IComponent> ComponentCreator::create4008(const std::string &value) const noexcept
    {
        std::unique_ptr<IComponent> ptr = std::make_unique<Comp4008>(value);
        return (ptr);
    }
    std::unique_ptr<IComponent> ComponentCreator::create4011(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4013(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4017(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4030(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4040(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4069(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4071(const std::string &value) const noexcept 
    {
        return (std::make_unique<Comp4071>(value));
    }
    std::unique_ptr<IComponent> ComponentCreator::create4081(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4094(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4514(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create4801(const std::string &value) const noexcept {}
    std::unique_ptr<IComponent> ComponentCreator::create2716(const std::string &value) const noexcept {}
}