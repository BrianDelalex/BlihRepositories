/*
** EPITECH PROJECT, 2019
** MapInitError.hpp
** File description:
** 
*/

#ifndef MAPINITERROR_HPP_
#define MAPINITERROR_HPP_

#include "exception"
#include "iostream"

class MapInitError : public std::exception
{
public:
    MapInitError(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); }
private:
    std::string _msg;
    std::string _comp;
};

#endif
