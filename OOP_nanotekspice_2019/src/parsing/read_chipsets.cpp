/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "parsing.hpp"
#include "errorInFile.hpp"

std::vector<std::string> *add_io(std::vector<std::string> *vec, const std::string &line)
{
    if (vec == nullptr)
        vec = new std::vector<std::string>;
    vec->push_back(line.substr(line.find_last_of(" \t", line.length()) + 1, line.length()));
    return (vec);
}

compIO *add_comp(compIO *compio, const std::string &line)
{
    if (compio->comp == nullptr)
        compio->comp = new std::vector<std::tuple<std::string, std::string>>;
    std::tuple<std::string, std::string> t;
    t =  std::tuple<std::string, std::string>(line.substr(0, line.find_first_of(" \t", 0)), \
                        line.substr(line.find_last_of(" \t", line.length()) + 1, line.length()));
    compio->comp->push_back(t);
    return (compio);
}

void read_chipsets(compIO *compio,const std::vector<std::string> &nts)
{
    int idx = 0;
    if (std::find(nts.begin(), nts.end(), ".chipsets:") == nts.end()) {
        errorInFile e("No chipset section", "Nts file error");
        throw e;
    }
    for (; idx < (int) nts.size() && nts[idx] != ".chipsets:"; idx = idx + 1);
    idx = idx + 1;
    for (; idx < (int) nts.size() && nts[idx][0] != '.'; idx = idx + 1)
    {
        if (isdigit(nts[idx][0]))
            compio = add_comp(compio, nts[idx]);
        if (nts[idx].substr(0, 5) == "input")
            compio->i = add_io(compio->i, nts[idx]);
        if (nts[idx].substr(0, 6) == "output")
            compio->o = add_io(compio->o, nts[idx]);
        if (nts[idx].substr(0, 4) == "true")
            compio->tr = add_io(compio->tr, nts[idx]);
        if (nts[idx].substr(0, 5) == "false")
            compio->fls = add_io(compio->fls, nts[idx]);
        if (nts[idx].substr(0, 5) == "clock")
            compio->clk = add_io(compio->clk, nts[idx]);
    }
}