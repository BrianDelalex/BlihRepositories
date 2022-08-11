
#include "game_components/IA.hpp"
#include "game_components/playerRegistry.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern struct playerRegistry_s *registry;

IA::IA(graph_handler_t *grhdl, Map *map, uint id, core::vector3df pos) : Player(grhdl, map, id, pos)
{
    _typedec = 0;
    _movedir = DIRECTION_NONE;
    _lastUpdate = NOW;
}

IA::~IA() {}

int IA::getCollideFromDir(enum direction dir)
{
    switch (dir)
    {
        case DIRECTION_UP:
            return ((int)CHECK_UP(DEFAULT_RAY_CHECK, COLLIDE));
            break;
        case DIRECTION_DOWN:
            return ((int)CHECK_DOWN(DEFAULT_RAY_CHECK, COLLIDE));
            break;
        case DIRECTION_RIGHT:
            return ((int)CHECK_RIGHT(DEFAULT_RAY_CHECK, COLLIDE));
            break;
        case DIRECTION_LEFT:
            return ((int)CHECK_LEFT (DEFAULT_RAY_CHECK, COLLIDE));
            break;
        default:
            return (-2);
    }
}

void IA::calculateNewDirection(void)
{
    int collide;
    int randomed;

    _movedir = (enum direction)(rand() % 4);
    collide = getCollideFromDir(_movedir);
    printf("%d %d %d\n", _typedec, collide, _movedir);
    if (collide == -1)
        _typedec = rand() % DEFAULT_RAY_CHECK;
    else if (collide < 1)
        calculateNewDirection();
    else
        _typedec = (rand() % (collide - 1));
}

void IA::update()
{
    if (DURATION<MILLISECONDS>(NOW - _lastUpdate).count() < UPDATE_CD_MS)
        return;
    _lastUpdate = NOW;
    core::vector3df pos = _textureNode->getPosition();
    int collide;

    while (_typedec == 0 || getCollideFromDir(_movedir) < 2)
        calculateNewDirection();
    if (_movedir == DIRECTION_DOWN)
        pos.Z -= 1.0f;
    else if (_movedir == DIRECTION_UP)
        pos.Z += 1.0f;
    else if (_movedir == DIRECTION_LEFT)
        pos.X -= 1.0f;
    else if (_movedir == DIRECTION_RIGHT)
        pos.X += 1.0f;
    _typedec--;
    _textureNode->setPosition(pos);
}

int IA::ray_check(float x, float z, enum raygetatt get, enum NodeID nodeid)
{
    core::line3d<f32> ray;
    core::vector3df detect = _textureNode->getPosition();
    core::vector3df start = _textureNode->getPosition();
    core::vector3df intersection;
    core::triangle3df hitTriangle;
    scene::ISceneCollisionManager* collMan = _grhdl->smgr->getSceneCollisionManager();

    detect.X = detect.X + x;
    detect.Z = detect.Z + z;
    ray.start = start;
    ray.end = detect;
    scene::ISceneNode *hitNode =
            collMan->getSceneNodeFromRayBB(
                    ray,
                    nodeid);
    if (hitNode != 0) {
        if (get == RAYCHECK_GETX) {
            return ((int)abs((int)hitNode->getPosition().X - (int)_textureNode->getPosition().X));
        } else if (get == RAYCHECK_GETZ) {
            return ((int)abs((int)hitNode->getPosition().Z - (int)_textureNode->getPosition().Z));
        }
    }
    return (-1);
}