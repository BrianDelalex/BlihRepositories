/*
** EPITECH PROJECT, 2019
** BadInput.hpp
** File description:
** Error when program input is wrong
*/

#ifndef BADINPUT_HPP_
#define BADINPUT_HPP_

#include "exception"
#include "iostream"

class BadInput : public std::exception
{
public:
    BadInput(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); }
private:
    std::string _msg;
    std::string _comp;
    int _switches;
};

#endif
