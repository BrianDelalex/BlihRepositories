/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** Operations
*/

#include "list"
#include "iostream"
#include "cmath"
#include "iomanip"
#include "groundhog.hpp"

int last_r = 0;

float find_relative_temp(std::list<float> temp)
{
    float res;
    if (temp.front() != 0)
    {
        res = ((temp.back() - temp.front()) * 100 / temp.front());
        std::cout << "r=" << std::round(res) << "%    ";
    } else
    {
        std::cout << "r=nan%    ";
        return (0);
    }
    
    return (res);
}

void find_temp_increase(int time, std::list<float> temp)
{
    float res = 0;
    auto it_next = temp.begin();
    it_next++;
    for (auto it = temp.begin(); it_next != temp.end(); it++, it_next++)
    {
       if (*it_next > *it)
        res += *it_next - *it;
    }
    res = res / time;
    if (res > 0)
        std::cout << std::setprecision(2) << "g=" << res << "   ";
    else
        std::cout << std::setprecision(2) << "g=" << res << "   ";
}

float find_standard_deviation(int time, std::list<float> temp)
{
    float res = 0;
    float half;
    float reslt = 0;
    if ((int)temp.size() > time)
        temp.pop_front();

    for (auto it = temp.begin(); it != temp.end(); it++) {
        res += *it;
    }
    half = res / time;
    for (auto p = temp.begin(); p != temp.end(); p++) {
        reslt += (*p - half) * (*p - half);
    }
    reslt = reslt / time;
    reslt = sqrt(reslt);
    return (reslt);
}

int process(int period, std::list<float> temp)
{
    int r;
    float res;
    int nb_switches = 0;
    if ((int)temp.size() > period) {
        find_temp_increase(period, temp);
        r = find_relative_temp(temp);
    }
    else
        std::cout << "g=nan    r=nan%    ";
    if ((int)temp.size() >= period) {
        res = find_standard_deviation(period, temp);
        std::cout << std::setprecision(3) << "s=" << res;
    }
    else
        std::cout << "s=nan";
    if ( last_r != 0 && ((r >= 0 && last_r <= 0) || (r <= 0 && last_r >= 0))) {
        nb_switches++;
        std::cout << "\ta switch occurs" << std::endl;
    }
    else
        std::cout << std::endl;
    last_r = r;
    return (nb_switches);
}