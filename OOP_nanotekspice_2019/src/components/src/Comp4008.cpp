/*
** EPITECH PROJECT, 2019
** Comp4008.cpp
** File description:
** 
*/

#include "Comp4008.hpp"

namespace nts
{

    Comp4008::Comp4008(const std::string &value) : _name(value), _type("4008")
    {
    }

    Comp4008::~Comp4008() {}

    Tristate Comp4008::compute(std::size_t pin)
    {
        
    }

    void Comp4008::setPin(std::size_t pin, Tristate value)
    {
        
    }

    void Comp4008::setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {
        Pin new_link = {(*other)->getPin(otherPin), other, otherPin};

        switch (pin)
        {
        case 1:
            a4 = new_link;
            return;
        case 2:
            b3 = new_link;
            return;
        case 3:
            a3 = new_link;
            return;
        case 4:
            b2 = new_link;
            return;
        case 5:
            a2 = new_link;
            return;
        case 6:
            b1 = new_link;
            return;
        case 7:
            a1 = new_link;
            return;
        case 9:
            c1 = new_link;
            return;
        case 15:
            b4 = new_link;
            return;
        case 10:
            s1 = new_link;
            return;
        case 11:
            s2 = new_link;
            return;
        case 12:
            s3 = new_link;
            return;
        case 13:
            s4 = new_link;
            return;
        case 14:
            co = new_link;
            return;
        default:
            break;
        }

    }

    void Comp4008::dump() const
    {

    }

    std::string Comp4008::getType() const { return (this->_type); }

    std::string Comp4008::getName() const { return (this->_name); }

    Tristate Comp4008::getPin(std::size_t pin) const
    {
        switch (pin)
        {
        case 1:
            return (a4.pin);
        case 2:
            return (b3.pin);
        case 3:
            return (a3.pin);
        case 4:
            return (b2.pin);
        case 5:
            return (a2.pin);
        case 6:
            return (b1.pin);
        case 7:
            return (a1.pin);
        case 9:
            return (c1.pin);
        case 10:
            return (s1.pin);
        case 11:
            return (s2.pin);
        case 12:
            return (s3.pin);
        case 13:
            return (s4.pin);
        case 14:
            return (co.pin);
        case 15:
            return (b4.pin);
        default:
            std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
            return (UNDEFINED);
        }
    }

}