/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef PLAYER_REGISTRY_HPP_
#define PLAYER_REGISTRY_HPP_

# include <list>

# include "game_components/Player.hpp"
class IA;

struct playerRegistry_s
{
    std::list<Player *> *_players;
};

struct playerRegistry_s *playerRegistry_init();

void playerRegistry_add_player(struct playerRegistry_s *registry, \
Player *newply);

bool playerRegistry_find_player(struct playerRegistry_s *registry, \
Player *toFind );

Player *playerRegistry_find_player_owning_node( \
struct playerRegistry_s *registry, scene::ISceneNode *node);

std::vector<Player *> *create_player(uint nbPlayer, graph_handler_t *grhdl, \
Map *map);

std::vector<IA *> *create_IA(uint nbPlayer, uint nbIA, graph_handler_t *grhdl, \
Map *map);

#endif