/*
** EPITECH PROJECT, 2019
** ComponentCreator.hpp
** File description:
** 
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <memory>
#include "IComponent.hpp"
#include "Components.hpp"
#include "errorCompCreation.hpp"

namespace nts
{
    class ComponentCreator
    {
    public:
        ComponentCreator();
        ~ComponentCreator();
        std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value);
    private:
        std::unique_ptr <IComponent>create4001(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4008(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4011(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4013(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4017(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4030(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4040(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4069(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4071(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4081(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4094(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4514(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create4801(const std::string &value) const noexcept;
        std::unique_ptr <IComponent>create2716(const std::string &value) const noexcept;
    };
}
#endif
