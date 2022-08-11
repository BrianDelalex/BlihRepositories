/*
** EPITECH PROJECT, 2019
** Constant.cpp
** File description:
** 
*/

#include "Constant.hpp"

namespace nts
{

    Constant::Constant(const std::string &value)
    {
        this->_name = value.substr(0, value.find_last_of(" ", value.length()));
        if (value.substr(value.find_last_of(" ", value.length()) + 1, value.length()) == "true") {
            this->pin.pin = TRUE;
            this->_type = "true";
        } else 
        {
            this->pin.pin = FALSE;
            this->_type = "false";
        }
    }

    void Constant::setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {

    }

    void Constant::dump() const
    {

    }

    std::string Constant::getType() const { return (this->_type); }

    std::string Constant::getName() const { return (this->_name); }
    Tristate Constant::getPin(std::size_t pin) const
    {
        if (pin == 1)
            return (this->pin.pin);
        std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
        return (UNDEFINED);
    }
}