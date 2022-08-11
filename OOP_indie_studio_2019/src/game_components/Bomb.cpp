/*
** EPITECH PROJECT, 2019
** Bomb.cpp
** File description:
** 
*/

#include "game_components/Bomb.hpp"

extern struct playerRegistry_s *registry;
extern std::list<Animator *> *animators;

Bomb::Bomb(graph_handler_t *grhdl, Player *ply)
{
    std::string meshPath = PROJECT_DIR;
    std::string texturePath = PROJECT_DIR;

    core::vector3df pos = center_bomb(ply->get_position());
    _start = NOW;
    meshPath.append("/assets/bomb/Bomb.obj");
    texturePath.append("/assets/bomb/Rough.png");
    _textureMesh = grhdl->smgr->getMesh(meshPath.c_str());
    if (!_textureMesh)
    {
        #pragma message "Throw error here"
        return;
    }
    _textureNode = grhdl->smgr->addMeshSceneNode( _textureMesh, 0, 0);
    pos.Y = pos.Y + 0.2f;
    if (_textureNode)
    {
        scene::ITriangleSelector* selector = grhdl->smgr->createTriangleSelector(_textureMesh, _textureNode);
        _textureNode->setScale(core::vector3df(6.0f));
        _textureNode->setTriangleSelector(selector);
        _textureNode->setMaterialFlag(video::EMF_LIGHTING, false);
        _textureNode->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);
        //_textureNode->setMaterialTexture(0, \
        grhdl->driver->getTexture(texturePath.c_str()));
        selector->drop();
    }
    _textureNode->setPosition(pos);
    this->_spreading = ply->get_bombSpreading();
    this->_grhdl = grhdl;
    this->_player_id = ply->get_id();
}

Bomb::~Bomb() {}

bool Bomb::explode()
{
    if (DURATION<MILLISECONDS>(NOW - _start).count() > 500)
        _textureNode->setID(COLLIDE);
    if (DURATION<SECONDS>(NOW - _start).count() < _cd)
        return (false);
    ray_check(_spreading, 0.0f);
    ray_check(-_spreading, 0.0f);
    ray_check(0.0f, _spreading);
    ray_check(0.0f, -_spreading);
    _grhdl->smgr->addToDeletionQueue(_textureNode);
    // Animator *anim = new Animator(_grhdl, _textureNode->getPosition());
    // std::cout << "                TA GRAND MERE                    \n";
    animators->push_back(new Animator(_grhdl, _textureNode->getPosition()));
    return (true);
}

void Bomb::animate()
{

}

void Bomb::ray_check(float x, float z)
{
    core::line3d<f32> ray;
    core::vector3df detect = _textureNode->getPosition();
    core::vector3df start = _textureNode->getPosition();
    core::vector3df intersection;
    core::triangle3df hitTriangle;
    scene::ISceneCollisionManager* collMan = _grhdl->smgr->getSceneCollisionManager();
    int playerDist;
    int caseDist;
    Player *ply;

    detect.X = detect.X + x;
    detect.Z = detect.Z + z;
    detect.Y = detect.Y + 0.6f;
    start.Y = start.Y + 0.6f;
    ray.start = start;
    ray.end = detect;
    irr::s32 bitmap = bitmap & 0x00000000;
    bitmap = bitmap | EXPLODE | NOEXPLODE;
    scene::ISceneNode *hitNode =
            collMan->getSceneNodeFromRayBB(
                    ray,
                    bitmap,
                    true);
    
    int mulX;

    if (x > 0)
        mulX = -1;
    else
        mulX = 1;
    int mulZ;
    if (z > 0)
        mulZ = -1;
    else
        mulZ = 1;
    if (hitNode) {
        if (x == 0)  {
            caseDist = abs(_textureNode->getPosition().Z - hitNode->getPosition().Z);
            for (int i = caseDist * -mulZ + ( 2 * mulZ); i != 0; i += mulZ * 2)
            {
                core::vector3df pos = _textureNode->getPosition();
                pos.Z += i;
                animators->push_back(new Animator(_grhdl, pos));
            }
        } else {
            caseDist = abs(_textureNode->getPosition().X - hitNode->getPosition().X);
            for (int i = caseDist * -mulX + ( 2 * mulX); i != 0; i += mulX * 2)
            {
                core::vector3df pos = _textureNode->getPosition();
                pos.X += i;
                animators->push_back(new Animator(_grhdl, pos));
            }
        }
    } else {
        
        if (x != 0) {
            for (int i = x; i != 0; i += mulX * 2)
            {
                core::vector3df pos = _textureNode->getPosition();
                pos.X += i;
                animators->push_back(new Animator(_grhdl, pos));
            }
        } else {
            for (int i = z; i != 0; i += mulZ * 2)
            {
                core::vector3df pos = _textureNode->getPosition();
                pos.Z += i;
                animators->push_back(new Animator(_grhdl, pos));
            }
        }
    }
    if (hitNode != 0 && hitNode->getID() & EXPLODE) {
        destroy_block(hitNode);
    }
    scene::ISceneNode *hitPlayer = 
            collMan->getSceneNodeFromRayBB(
                ray,
                PLAYER,
                true);
    if (hitPlayer != 0)
    {
        ply = playerRegistry_find_player_owning_node( \
        registry , hitPlayer);
        if (x == 0)
            playerDist = abs(_textureNode->getPosition().Z - hitPlayer->getPosition().Z);
        else
            playerDist = abs(_textureNode->getPosition().X - hitPlayer->getPosition().X);
    }
    if (hitPlayer && !player_has_been_hit(ply) && hitNode)
    {
        if ((caseDist > playerDist && (x > 0 || z > 0) ) || (caseDist < playerDist) && (x < 0 || z < 0))
            if (ply) {
                ply->blow_up(_player_id);
                hited_ply.push_back(ply);
            }
    } else if (hitPlayer && !player_has_been_hit(ply))
        if (ply) {
            ply->blow_up(_player_id);
            hited_ply.push_back(ply);
        }
}

bool Bomb::player_has_been_hit(Player *ply)
{
    for (auto it = hited_ply.begin(); it != hited_ply.end(); it++)
        if (*it == ply)
            return (true);
    return (false);
}

scene::IMeshSceneNode *Bomb::get_textureNode()
{
    return (_textureNode);
}

core::vector3df Bomb::center_bomb(core::vector3df pos)
{
    core::vector3di newpos;
    bool x;
    bool z;

    newpos.X = round(pos.X);
    newpos.Z = round(pos.Z);
    if (abs(newpos.X) % 2 == 1)
        x = true;
    else
        x = false;
    if (abs(newpos.Z) % 2 == 1)
        z = true;
    else
        z = false;

    if (x) {
        if (newpos.X > pos.X)
            newpos.X -= 1;
        else
            newpos.X += 1;
    }
    if (z) {
        if (newpos.Z > pos.Z)
            newpos.Z -= 1;
        else
            newpos.Z += 1;
    }
    core::vector3df newposf;
    newposf.X = (float) newpos.X;
    newposf.Z = (float) newpos.Z;
    newposf.Y = pos.Y;
    return (newposf);
}

void Bomb::destroy_block(scene::ISceneNode *hitNode)
{
    _grhdl->smgr->addToDeletionQueue(hitNode);
    int power_rand = rand() % 8;
    POWER_UP pow = ANY;
    if (power_rand == 0) {
        std::cout << "BombUp\n";
        pow = BombUp;
    }
    if (power_rand == 1) {
        std::cout << "SpeedUp\n";
         pow = SpeedUp;
    }
    if (power_rand == 2) {
        std::cout << "FireUp\n";
        pow = FireUp;
    }
    if (power_rand == 3) {
        std::cout << "WallPass\n";
         pow = FireUp;
    }
    if (pow != ANY) 
        create_powerup(_grhdl, pow, hitNode->getPosition());

}