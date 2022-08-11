/*
** EPITECH PROJECT, 2019
** errorCompCreation.cpp
** File description:
** 
*/

#include "errorCompCreation.hpp"

errorCompCreation::errorCompCreation(const std::string &msg, const std::string &comp) : exception()
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &errorCompCreation::getComponent() const { return (this->_comp); }