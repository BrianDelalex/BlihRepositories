/*
** EPITECH PROJECT, 2019
** Clock.cpp
** File description:
** 
*/

#include "Clock.hpp"

namespace nts
{

    Clock::Clock(const std::string &value) : _name(value), _type("clock")
    {
    }

    void Clock::setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {

    }

    void Clock::dump() const
    {

    }

    std::string Clock::getType() const { return (this->_type); }
    
    std::string Clock::getName() const { return (this->_name); }

    Tristate Clock::getPin(std::size_t pin) const
    {
        if (pin == 1)
            return (this->pin.pin);
        std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
        return (UNDEFINED);
    }
}