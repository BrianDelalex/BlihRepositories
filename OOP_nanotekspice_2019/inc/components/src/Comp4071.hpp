/*
** EPITECH PROJECT, 2019
** Comp4071.hpp
** File description:
** 
*/

#ifndef COMP4071_HPP_
#define COMP4071_HPP_

#include "IComponent.hpp"

namespace nts
{

class Comp4071 : public IComponent
{
public:
    Comp4071(const std::string &value);
    ~Comp4071();
    Tristate compute(std::size_t pin = 1);
    void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
    void setPin(std::size_t pin, Tristate value);
    void dump() const;
    std::string getType() const override;
    std::string getName() const;
    Tristate getPin(std::size_t pin) const;
private:
    const std::string _name;
    const std::string _type;
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
};

}

#endif
