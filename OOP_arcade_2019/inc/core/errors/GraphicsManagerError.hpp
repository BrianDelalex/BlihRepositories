/*
** EPITECH PROJECT, 2019
** GraphicsManagerError.hpp
** File description:
** 
*/

#ifndef GRAPHICSMANAGERERROR_HPP_
#define GRAPHICSMANAGERERROR_HPP_

#include "exception"
#include "iostream"

class GraphicsManagerError : public std::exception
{
public:
    GraphicsManagerError(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); };
private:
    std::string _msg;
    std::string _comp;
private:
};

#endif
