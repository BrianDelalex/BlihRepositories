/*
** EPITECH PROJECT, 2019
** errorInFile.hpp
** File description:
** Erorrs of nts files
*/

#include "invalidLink.hpp"

invalidLink::invalidLink(const std::string &msg, const std::string &comp) : exception()
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &invalidLink::getComponent() const { return (this->_comp); }

const char *invalidLink::what() const noexcept { return (this->_msg.data()); };