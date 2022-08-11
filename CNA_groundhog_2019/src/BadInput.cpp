/*
** EPITECH PROJECT, 2019
** MapInitError.cpp
** File description:
** 
*/

#include "BadInput.hpp"

BadInput::BadInput(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

const std::string &BadInput::getComponent() const
{
    return (this->_comp);
}
