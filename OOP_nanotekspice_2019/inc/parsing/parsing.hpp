/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

/* INCLUDES */
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <memory>
#include "Components.hpp"
#include "invalidLink.hpp"

struct link_s
{
    std::string comp1;
    size_t pin1;
    std::string comp2;
    size_t pin2;
};

typedef struct link_s link;

struct compIO_s
{
    std::vector<std::string> *i;
    std::vector<std::string> *o;
    std::vector<std::string> *clk;
    std::vector<std::string> *tr;
    std::vector<std::string> *fls;
    std::vector<std::tuple<std::string, std::string>> *comp;
    std::vector<link> *links;
};

typedef struct compIO_s compIO;

/* PROTOTYPES */
std::vector<std::string> read_file(const std::string &file);
compIO *create_compIO(const std::vector<std::string> &nts);
void read_chipsets(compIO *compio,const std::vector<std::string> &nts);
void read_links(compIO *compio, const std::vector<std::string> &nts);
int check_input(int ac, char **av);
void delete_compIO(compIO *compio);
int create_comps(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::tuple<std::string, std::string>> &compName);
int create_inputs(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::string> &iName, int ac, char **av);
void create_output(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<std::string> &outputName);
int link_components(std::vector<std::unique_ptr<nts::IComponent>> *comps, std::vector<link> links);
void process(std::vector<std::unique_ptr<nts::IComponent>> *comps);

