/*
** EPITECH PROJECT, 2019
** Constant.hpp
** File description:
** 
*/

#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Constant : public IComponent
    {
    public:
        Constant(const std::string &value);
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        void dump() const;
        std::string getType() const;
        std::string getName() const;
        Tristate getPin(std::size_t pin) const;
    private:
        std::string _name;
        std::string _type;
        Pin pin;
    };
}

#endif
