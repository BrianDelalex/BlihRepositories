/*
** EPITECH PROJECT, 2019
** groundhog.hpp
** File description:
** groundhog header file
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <list>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include "parsing.hpp"

void loop(int period);
bool sorting_diff(std::tuple<float, float> a, std::tuple<float, float> b);
int process(int period, std::list<float> temp);
float find_relative_temp(std::list<float> temp);
void find_temp_increase(int time, std::list<float> temp);
float find_standard_deviation(int time, std::list<float> temp);

#endif