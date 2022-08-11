/*
** EPITECH PROJECT, 2019
** Comp4001.hpp
** File description:
** 
*/

#ifndef COMP4001_HPP_
#define COMP4001_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Comp4001 : public IComponent
    {
    public:
        Comp4001(const std::string &value);
        ~Comp4001();
        Tristate compute(std::size_t pin = 1);
        void setPin(std::size_t pin, Tristate value);
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        void dump() const;
        std::string getType() const;
        std::string getName() const;
        Tristate getPin(std::size_t pin) const;
    private:
        Pin a1; // 1
        Pin b1; // 2
        Pin o1; // 3
        Pin a2; // 5
        Pin b2; // 6
        Pin o2; // 4
        Pin a3; // 8
        Pin b3; // 9
        Pin o3; // 10
        Pin a4; // 12
        Pin b4; // 13
        Pin o4; // 11
        const std::string _name;
        const std::string _type;
    };
}
#endif
