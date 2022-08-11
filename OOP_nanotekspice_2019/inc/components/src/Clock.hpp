/*
** EPITECH PROJECT, 2019
** Clock.hpp
** File description:
** 
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Clock : public IComponent
    {
    public:
        Clock(const std::string &value);
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        void dump() const;
        std::string getType() const;
        std::string getName() const;
        Tristate getPin(std::size_t pin) const;
    private:
        const std::string _name;
        const std::string _type;
        Pin pin;
    };
}

#endif
