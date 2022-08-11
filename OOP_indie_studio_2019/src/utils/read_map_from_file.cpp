/*
** EPITECH PROJECT, 2019
** read_map_from_file.cpp
** File description:
** read map file and fill std::vector<std::string>
*/

#include "utils/utils.hpp"

std::vector<std::string> *read_map_from_file(std::string path)
{
    std::vector<std::string> *map = new std::vector<std::string>;
    std::ifstream file;
    std::string buf;
    file.open(path);
    while (std::getline(file, buf, '\n')) {
        map->push_back(buf);
    }
    return (map);
}