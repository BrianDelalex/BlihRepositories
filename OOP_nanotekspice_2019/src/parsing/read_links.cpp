/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "errorInFile.hpp"
#include "parsing.hpp"

void read_links(compIO *compio, const std::vector<std::string> &nts)
{
    std::vector<std::string>::const_iterator it = std::find(nts.begin(), nts.end(), ".links:");
    if (it == nts.end())
    { 
        throw errorInFile("No link section", "Nts File Error");
    }
    compio->links = new std::vector<link>;
    it++;
    for (;it != nts.end(); it++)
    {
        link lk;
        lk.comp1 = it->substr( 0, it->find_first_of( ":", 0 ) );
        lk.pin1 = std::stoi( it->substr( it->find_first_of( ":", 0 ) + 1, it->find_first_of( " \t", 0) ) );
        lk.comp2 = it->substr( it->find_last_of( " \t", it->length()) + 1,  it->find_last_of(":", it->length() ) - (it->find_last_of( " \t", it->length()) + 1));
        lk.pin2 = std::stoi( it->substr( it->find_last_of(":", it->length() ) + 1, it->length() ) );
        compio->links->push_back(lk);
    }
}