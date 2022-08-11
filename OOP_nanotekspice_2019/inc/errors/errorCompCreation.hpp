/*
** EPITECH PROJECT, 2019
** errorCompCreation.hpp
** File description:
** 
*/

#ifndef ERRORCOMPCREATION_HPP_
#define ERRORCOMPCREATION_HPP_

#include <exception>
#include <iostream>

class errorCompCreation : public std::exception
{
public:
    errorCompCreation(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); };
private:
    std::string _msg;
    std::string _comp;
};

#endif
