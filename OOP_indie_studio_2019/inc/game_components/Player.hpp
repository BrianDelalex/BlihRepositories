/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** 
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

# include <SFML/Audio/Sound.hpp>
# include <SFML/Audio/SoundBuffer.hpp>

# include "graphics/graphics.hpp"
# include "game_components/Map.hpp"
# include "game_components/Bomb.hpp"
# include "utils/time_management.hpp"
# include "game_components/playerControl.hpp"

#define UPDATE_CD_PLY_MS 25
#define DROP_CD_MS 250

class Map;
class Bomb;

struct buffs_t
{
    uint bomb;
    uint spread;
    uint speed;
    uint lives;
    bool wallpass;
};

class Player
{
public:
    Player(graph_handler_t *grhdl, Map *map, uint id, core::vector3df pos);
    void init(std::string mesh_path, std::string texture_path);
    ~Player(void);
    void update(void);
    void blow_up(uint player_id);
    float get_bombSpreading(void);
    core::vector3df get_position(void);
    scene::IAnimatedMeshSceneNode *get_node(void);
    void set_control(struct playerControl_s controls);
    uint get_id(void);
    bool is_alive();
    void take_buff(core::vector3df detect);
    struct buffs_t *get_buffs(void);
protected:
    void play_sound();
    graph_handler_t *_grhdl;
    MyEventReceiver *_evthdl;
    Map *_map;
    scene::IAnimatedMesh *_textureMesh;
    scene::IAnimatedMeshSceneNode *_textureNode;
    core::vector3df _pos;
    int _anim;
    std::vector<Bomb *> *_bomb;
    TIMEPOINT _dropTime;
    float _bombSpreading;
    uint _id;
    uint _lives;
    float _speed;
    bool _alive;
    struct playerControl_s _controls;
    TIMEPOINT _lastUpdated;
    uint _bombStock;
    bool _collide;
    sf::Sound _sound;
    sf::SoundBuffer _buffer;
    struct buffs_t *buffs;

};

#endif
