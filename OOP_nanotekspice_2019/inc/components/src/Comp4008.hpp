/*
** EPITECH PROJECT, 2019
** Comp4008.hpp
** File description:
** 
*/

#ifndef COMP4008_HPP_
#define COMP4008_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Comp4008 : public IComponent
    {
    public:
        Comp4008(const std::string &value);
        ~Comp4008();
        void setPin(std::size_t pin, Tristate value);
        Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        void dump() const;
        std::string getType() const;
        std::string getName() const;
        Tristate getPin(std::size_t pin) const;
    private:
        Pin a4; // 1
        Pin b3; // 2
        Pin a3; // 3
        Pin b2; // 4
        Pin a2; // 5
        Pin b1; // 6
        Pin a1; // 7
        Pin c1; // 9
        Pin s1; // 10
        Pin s2; // 11
        Pin s3; // 12
        Pin s4; // 13
        Pin co; // 14
        Pin b4; // 15
        const std::string _name;
        const std::string _type;
    };
}
#endif
