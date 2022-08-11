/*
** EPITECH PROJECT, 2019
** Player.hpp
** File description:
** 
*/

#ifndef IA_HPP_
#define IA_HPP_

# include "graphics/graphics.hpp"
# include "game_components/Map.hpp"
# include "game_components/Bomb.hpp"
# include "utils/time_management.hpp"
# include "game_components/playerControl.hpp"
# include "game_components/Player.hpp"

class Map;
class Bomb;
class Player;

#define BLK_TRANSLATION(blk) (blk * 2)

#define DEFAULT_RAY_CHECK 5

#define CHECK_UP(blk, nodeid)    (ray_check(0, BLK_TRANSLATION(blk), RAYCHECK_GETZ, nodeid))
#define CHECK_DOWN(blk, nodeid)  (ray_check(0, BLK_TRANSLATION(blk) * -1, RAYCHECK_GETZ, nodeid)) 
#define CHECK_RIGHT(blk, nodeid) (ray_check(BLK_TRANSLATION(blk), 0, RAYCHECK_GETX, nodeid))
#define CHECK_LEFT(blk, nodeid)  (ray_check(BLK_TRANSLATION(blk) *-1, 0, RAYCHECK_GETX, nodeid))
#define UPDATE_CD_MS 500

enum direction
{
    DIRECTION_UP    = 0,
    DIRECTION_DOWN  = 1,
    DIRECTION_RIGHT = 2,
    DIRECTION_LEFT  = 3,
    DIRECTION_NONE  = 4
};

enum raygetatt
{
    RAYCHECK_GETX = 0,
    RAYCHECK_GETZ = 1
};

class IA : public Player
{
public:
    IA(graph_handler_t *grhdl, Map *map, uint id, core::vector3df pos);
    ~IA();
    void update(void);
    void calculateNewDirection(void);
    int ray_check(float x, float z, enum raygetatt get, enum NodeID nodeid);
    int getCollideFromDir(enum direction dir);
private:
    enum direction _movedir;
    int _typedec;
    TIMEPOINT _lastUpdate;
};

#endif
