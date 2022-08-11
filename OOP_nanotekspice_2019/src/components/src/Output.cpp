/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "Output.hpp"

namespace nts
{

    Output::Output(const std::string &value) : _name(value), _type("output")
    {
        this->pin.pin = nts::UNDEFINED;
    }

    void Output::setLink(std::size_t pin __attribute__((unused)), std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {
        this->pin.other = other;
        this->pin.otherPin = otherPin;
    }

    void Output::setPin(std::size_t pin __attribute__((unused)), Tristate value)
    {
        this->pin.pin = value;
    }

    nts::Tristate Output::compute(std::size_t pin __attribute__((unused)))
    {
        this->pin.pin = (*this->pin.other)->compute(this->pin.otherPin);
        return (this->pin.pin);
    }

    void Output::dump() const
    {
        if (pin.pin == TRUE)
            std::cout << this->_name << "=" << 1 << std::endl;
        else if (pin.pin == FALSE) 
            std::cout << this->_name << "=" << 0 << std::endl;
    }

    std::string Output::getType() const { return (this->_type); }

    std::string Output::getName() const { return (this->_name); }

    Tristate Output::getPin(std::size_t pin) const
    {
        if (pin == 1)
            return (this->pin.pin);
        else 
        {
            std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
        }
    }
}