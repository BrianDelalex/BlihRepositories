/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "IComponent.hpp"

namespace nts
{

    class Output : public IComponent
    {
    public:
        Output(const std::string &value);
        nts::Tristate compute(std::size_t pin = 1);
        void setPin(std::size_t pin, Tristate value);
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        void dump() const;
        std::string getType() const override;
        std::string getName() const;
        Tristate getPin(std::size_t pin) const;
    private:
        const std::string _name;
        const std::string _type;
        Pin pin;
    };
}
#endif