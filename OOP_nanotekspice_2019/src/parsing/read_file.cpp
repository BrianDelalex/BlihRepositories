/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "parsing.hpp"

std::vector<std::string> read_file(const std::string &file)
{
    std::ifstream istream;
    std::string str;
    std::vector<std::string> vec;

    istream.open(file);
    if (!istream.is_open())
    {
        std::cerr << "Can't open " << file << std::endl;
        exit (84);
    }
    while (std::getline(istream, str, '\n'))
        if (!str.empty() && str != "" && str[0] != '#')
            vec.push_back(str);
    istream.close();
    return (vec);
} 