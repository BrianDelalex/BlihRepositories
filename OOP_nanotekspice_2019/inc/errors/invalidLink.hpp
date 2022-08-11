/*
** EPITECH PROJECT, 2019
** invalidLink.hpp
** File description:
** Erorrs of nts files
*/

#ifndef INVALIDLINK_HPP_
#define INVALIDLINK_HPP_

#include <exception>
#include <iostream>

class invalidLink : public std::exception
{
public:
    invalidLink(const std::string &msg, const std::string &comp = "Unknow");
    virtual std::string const &getComponent() const;
    virtual const char *what() const noexcept override;
private:
    std::string _msg;
    std::string _comp;
};

#endif