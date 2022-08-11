/*
** EPITECH PROJECT, 2019
** Bomb.hpp
** File description:
** 
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

# include <list>

# include "graphics/graphics.hpp"
# include "utils/time_management.hpp"
# include "game_components/playerRegistry.hpp"
# include "game_components/powerUp.hpp"
# include "graphics/Animator.hpp"

class Bomb
{
public:
    Bomb(graph_handler_t *grhdl, Player *ply);
    ~Bomb();
    bool explode();
    void ray_check(float x, float z);
    scene::IMeshSceneNode *get_textureNode();
    bool player_has_been_hit(Player *ply);
private:
    void play_sound();
    core::vector3df center_bomb(core::vector3df pos);
    void destroy_block(scene::ISceneNode *hitNode);
    void animate();
    graph_handler_t *_grhdl;
    scene::IMesh *_textureMesh;
    scene::IMeshSceneNode *_textureNode;
    TIMEPOINT _start;
    float _spreading;
    const int _cd = 2;
    uint _player_id;
    std::vector<Player *> hited_ply;
};

#endif
