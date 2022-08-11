/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "Input.hpp"

namespace nts
{

    Input::Input(const std::string &name) : _name(name), _type("input") {}

    Input::Input(const std::string &name, nts::Tristate value) : _name(name), _type("input")
    {
        this->pin.pin = value;
    }

    Input::~Input() {}

    void Input::setPin(std::size_t pin __attribute__((unused)), nts::Tristate value)
    {
        this->pin.pin = value;
    }

    void Input::setLink(std::size_t pin __attribute__((unused)), std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {
        this->pin.other = other;
        this->pin.otherPin = otherPin;
    }

    void Input::dump() const
    {
    }

    std::string Input::getName() const { return (this->_name);}

    Tristate Input::compute(std::size_t pin __attribute__((unused)))
    {
        return (this->pin.pin);
    }

    std::string Input::getType() const { return (this->_type); }
    
    Tristate Input::getPin(std::size_t pin) const
    {
        if (pin == 1)
            return (this->pin.pin);
        std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
        return (UNDEFINED);
    }
}