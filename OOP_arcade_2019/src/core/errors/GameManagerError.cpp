/*
** EPITECH PROJECT, 2019
** GameManagerError.cpp
** File description:
** 
*/

#include "GameManagerError.hpp"

GameManagerError::GameManagerError(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &GameManagerError::getComponent() const
{
    return (this->_comp);
}
