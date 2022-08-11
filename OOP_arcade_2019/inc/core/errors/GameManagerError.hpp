/*
** EPITECH PROJECT, 2019
** GameManagerError.hpp
** File description:
** 
*/

#ifndef GAMEMANAGERERROR_HPP_
#define GAMEMANAGERERROR_HPP_

#include <exception>
#include <iostream>

class GameManagerError : public std::exception
{
public:
    GameManagerError(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override { return (this->_msg.data()); };
private:
    std::string _msg;
    std::string _comp;
private:
};

#endif
