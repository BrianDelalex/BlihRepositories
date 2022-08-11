/*
** EPITECH PROJECT, 2019
** GraphicsManagerError.cpp
** File description:
** 
*/

#include "GraphicsManagerError.hpp"

GraphicsManagerError::GraphicsManagerError(const std::string &msg, const std::string &comp)
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &GraphicsManagerError::getComponent() const
{
    return (this->_comp);
}

