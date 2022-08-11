/*
** EPITECH PROJECT, 2019
** playerRegistry.cpp
** File description:
** Bundle of function to use playerRegistry
*/

#include "game_components/playerRegistry.hpp"

struct playerRegistry_s *playerRegistry_init()
{
    struct playerRegistry_s *registry = new struct playerRegistry_s;
    registry->_players = new std::list<Player *>;
    return (registry);
}

void playerRegistry_add_player(struct playerRegistry_s *registry, \
Player *newply)
{
    if (registry != nullptr && registry->_players != nullptr)
        registry->_players->push_back(newply);
}

bool playerRegistry_find_player(struct playerRegistry_s *registry, \
Player *toFind )
{
    if (registry == nullptr && registry->_players != nullptr)
        return (false);
    for (auto it = registry->_players->begin(); \
    it != registry->_players->end(); it++) {
        if (*it == toFind)
            return (true);
    }
    return (false);
}

Player *playerRegistry_find_player_owning_node( \
struct playerRegistry_s *registry, scene::ISceneNode *node)
{
    if (registry == nullptr && registry->_players != nullptr)
        return (nullptr);
    for (auto it = registry->_players->begin(); \
    it != registry->_players->end(); it++) {
        if ((*it)->get_node() == node)
            return (*it);
    }
    return (nullptr);
}