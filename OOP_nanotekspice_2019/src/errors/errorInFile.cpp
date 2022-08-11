/*
** EPITECH PROJECT, 2019
** errorInFile.hpp
** File description:
** Erorrs of nts files
*/

#include "errorInFile.hpp"

errorInFile::errorInFile(const std::string &msg, const std::string &comp) : exception()
{
    this->_msg = msg;
    this->_comp = comp;
}

std::string const &errorInFile::getComponent() const { return (this->_comp); }