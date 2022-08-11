/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <IComponent.hpp>

namespace nts
{

    class Input : public IComponent
    {
    public:
        Input(const std::string &name);
        Input(const std::string &name, nts::Tristate value);
        ~Input();
        Tristate compute(std::size_t pin = 1);
        void setPin(std::size_t pin, nts::Tristate value);
        void dump() const;
        void setLink(std::size_t pin, std::unique_ptr<nts::IComponent> *other, std::size_t otherPin);
        std::string getName() const;
        std::string getType() const override;
        Tristate getPin(std::size_t pin) const;
    private:
        const std::string _name;
        const std::string _type;
        Pin pin;
    };

}
#endif