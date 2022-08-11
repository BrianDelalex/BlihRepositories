/*
** EPITECH PROJECT, 2019
** MapInitError.cpp
** File description:
** 
*/

#include "MapInitError.hpp"

MapInitError::MapInitError(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

const std::string &MapInitError::getComponent() const
{
    return (this->_comp);
}
