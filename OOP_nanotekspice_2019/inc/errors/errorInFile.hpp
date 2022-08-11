/*
** EPITECH PROJECT, 2019
** errorInFile.hpp
** File description:
** Erorrs of nts files
*/

#ifndef ERRORINFILE_HPP_
#define ERRORINFILE_HPP_

#include <exception>
#include <iostream>

class errorInFile : public std::exception
{
public:
    errorInFile(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); };
private:
    std::string _msg;
    std::string _comp;
};

#endif