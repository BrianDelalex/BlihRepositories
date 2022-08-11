/*
** EPITECH PROJECT, 2019
** Animator.hpp
** File description:
** 
*/

#ifndef ANIMATOR_HPP_
#define ANIMATOR_HPP_

# include <vector>

# include "graphics/graphics.hpp"
# include "utils/time_management.hpp"

# define ANIM_DURATION_MS 500


class Animator
{
public:
    Animator(graph_handler_t *grhdl, core::vector3df pos);
    ~Animator();
    void create_anim(core::vector3df pos);
    bool update();
private:
    graph_handler_t *_grhdl;
    scene::IParticleSystemSceneNode * _anim;
    const TIMEPOINT _start; 
};

#endif
