/*
** EPITECH PROJECT, 2019
** Comp4071.cpp
** File description:
** 
*/

#include "Comp4071.hpp"

namespace nts
{

    Comp4071::Comp4071(const std::string &value) : _name(value), _type("4071")
    {

    }

    Comp4071::~Comp4071() {}

    Tristate Comp4071::compute(std::size_t pin)
    {
        if (pin == 3)
        {
            this->a1.pin = (*this->a1.other)->getPin(this->a1.otherPin);
            this->b1.pin = (*this->b1.other)->getPin(this->b1.otherPin);
            this->o1.pin = (Tristate) (this->a1.pin || this->b1.pin);
            return (this->o1.pin);
        }
        if (pin == 4)
        {
            this->a2.pin = (*this->a2.other)->getPin(this->a2.otherPin);
            this->b2.pin = (*this->b2.other)->getPin(this->b2.otherPin);
            this->o2.pin = (Tristate) (this->a2.pin || this->b2.pin);
            return (this->o2.pin);
        }
        if (pin == 10)
        {
            this->a3.pin = (*this->a3.other)->getPin(this->a3.otherPin);
            this->b3.pin = (*this->b3.other)->getPin(this->b3.otherPin);
            this->o3.pin = (Tristate) (this->a3.pin || this->b3.pin);
            return (o3.pin);
        }
        if (pin == 11)
        {
            this->a4.pin = (*this->a4.other)->getPin(this->a4.otherPin);
            this->b4.pin = (*this->b4.other)->getPin(this->b4.otherPin);
            this->o4.pin = (Tristate) (this->a4.pin || this->b4.pin);
            return (o4.pin);
        }
    }

    void Comp4071::setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin)
    {
        Pin new_link = {UNDEFINED, other, otherPin};

        switch (pin)
        {
        //INPUTS
        case 1:
            a1 = new_link;
            return;
        case 2:
            b1 = new_link;
            return;
        case 5:
            a2 = new_link;
            return;
        case 6:
            b2 = new_link;
            return;
        case 8:
            a3 = new_link;
            return;
        case 9:
            b3 = new_link;
            return;
        case 12:
            a4 = new_link;
            return;
        case 13:
            b4 = new_link;
            return;
        //OUTPUTS
        case 3:
            new_link.pin = UNDEFINED;
            o1 = new_link;
            return;
        case 4:
            new_link.pin = UNDEFINED;
            o2 = new_link;
            return;
        case 10:
            new_link.pin = UNDEFINED;
            o3 = new_link;
            return;
        case 11:
            new_link.pin = UNDEFINED;
            o4 = new_link;
            return;
        default:
            break;
        }
    }

    void Comp4071::dump() const
    {

    }

    void Comp4071::setPin(std::size_t pin, Tristate value)
    {
    }

    std::string Comp4071::getType() const { return (this->_type); }

    std::string Comp4071::getName() const { return (this->_name); }

    Tristate Comp4071::getPin(std::size_t pin) const
    {
        switch (pin)
        {
        case 1:
            return (this->a1.pin);
        case 2:
            return (this->b1.pin);
        case 3:
            return (this->o1.pin);
        case 4:
            return (this->o2.pin);
        case 5:
            return (this->a2.pin);
        case 6:
            return (this->b2.pin);
        case 8:
            return (this->a3.pin);
        case 9:
            return (this->b3.pin);
        case 10:
            return (this->o3.pin);
        case 11:
            return (this->o4.pin);
        case 12:
            return (this->a4.pin);
        case 13:
            return (this->b4.pin);
        default:
            std::cerr << "Unknow pin " << pin << "for " << this->_name << "component.\n";
            return (UNDEFINED);
        }
    }

}