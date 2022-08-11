/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <memory>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;

    public:
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin) = 0;
        virtual void setPin(std::size_t pin, Tristate value) = 0;
        virtual void dump() const = 0;
        virtual std::string getType() const = 0;
        virtual std::string getName() const = 0;
        virtual Tristate getPin(std::size_t pin) const = 0;
    };

    struct Pin_s
    {
        Tristate pin;
        std::unique_ptr<nts::IComponent> *other;
        size_t otherPin;
    };
    typedef struct Pin_s Pin;
}

#endif