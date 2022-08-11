/*
** EPITECH PROJECT, 2019
** Player.cpp
** File description:
** 
*/

#include "game_components/Player.hpp"

Player::Player(graph_handler_t *grhdl, Map *map, uint id, core::vector3df pos)
{
    this->_grhdl = grhdl;
    this->_evthdl = grhdl->evthdl;
    this->_map = map;
    _bomb = new std::vector<Bomb *>;
    _bomb->push_back(nullptr);
    _anim = 0;
    _dropTime = NOW;
    this->_id = id;
    this->_bombSpreading = 2.0f;
    this->_pos = pos;
    this->_lives = 3;
    _speed = 0.2f;
    _lastUpdated = NOW;
    _alive = true;
    _bombStock = 1;
    _collide = true;
    buffs = new struct buffs_t;
    buffs->bomb = 0;
    buffs->spread = 0;
    buffs->speed = 0;
    buffs->wallpass = false;
}

Player::~Player() {}

void Player::init(std::string mesh_path, std::string texture_path)
{
    std::cout << "player id: " << _id << "\n";
    video::SMaterial material;
    _textureMesh = (scene::SAnimatedMesh *) _grhdl->smgr->getMesh(mesh_path.c_str());
    if (!_textureMesh)
    {
        #pragma message "Throw error here"
        return;
    }
    _textureNode = _grhdl->smgr->addAnimatedMeshSceneNode( _textureMesh, 0, PLAYER);
    _textureNode->setScale(core::vector3df(1.5f));
    material.Lighting = false;
    material.NormalizeNormals = true;
    _textureNode->getMaterial(0) = material;
    if (_textureNode)
    {
        scene::ITriangleSelector* selector = _grhdl->smgr->createTriangleSelector(_textureNode);
        _textureNode->setTriangleSelector(selector);
        //_textureNode->setMaterialFlag(video::EMF_LIGHTING, false);
        _textureNode->setMaterialTexture(0, \
        _grhdl->driver->getTexture(texture_path.c_str()));
        selector->drop();
    }
    _textureNode->setPosition(_pos);
}

void Player::update()
{
    for (uint i = 0; i < _bomb->size(); i++) 
    {
        if ((*_bomb)[i] != nullptr)
        {
            if ((*_bomb)[i]->explode())
            {
                play_sound();
                _sound.play();
                delete (*_bomb)[i];
                (*_bomb)[i]  = nullptr;
            }
        }
    }
    if (DURATION<MILLISECONDS>(NOW - _lastUpdated).count() < UPDATE_CD_PLY_MS || _alive == false)
        return;
    _lastUpdated = NOW;
    irr::core::vector3df pos = _textureNode->getPosition();
    irr::core::vector3df detect = pos;
    if (_anim == 0) {
        _textureNode->setFrameLoop(0, 26);
        _anim = 1;
    }
    if(_evthdl->IsKeyDown(_controls._bomb) && DURATION<MILLISECONDS>(NOW - _dropTime).count() > DROP_CD_MS)
    {
        for (uint i = 0; i < _bomb->size(); i++)
            if ((*_bomb)[i] == nullptr) {
                std::cout << "New bomb " << i << std::endl;
                (*_bomb)[i] = new Bomb(_grhdl, this);
                _dropTime = NOW;
                break;
            }
    }

    if(_evthdl->IsKeyDown(_controls._up)) {
        pos.Z += _speed;
        detect.Z += 1.2f;
        _textureNode->setRotation(core::vector3df(0, 180, 0));
    } else if(_evthdl->IsKeyDown(_controls._down)) {
        pos.Z -= _speed;
        detect.Z -= 1.2f;
        _textureNode->setRotation(core::vector3df(0, 0, 0));
    } else if(_evthdl->IsKeyDown(_controls._left)) {
        pos.X -= _speed;
        detect.X -= 1.2f;
        _textureNode->setRotation(core::vector3df(0, 90, 0));
    } else if(_evthdl->IsKeyDown(_controls._right)) {
        pos.X += _speed;
        detect.X += 1.2f;
        _textureNode->setRotation(core::vector3df(0, -90, 0));
    } else
    {
        if (_anim == 1) {
            _textureNode->setFrameLoop(27, 76);
            _anim = 0;
        }
    }
    core::line3d<f32> ray;
    ray.start = _textureNode->getPosition();
    ray.end = detect;
    core::vector3df intersection;
    core::triangle3df hitTriangle;
    scene::ISceneCollisionManager* collMan = _grhdl->smgr->getSceneCollisionManager();
    scene::ISceneNode * selectedSceneNode =
            collMan->getSceneNodeAndCollisionPointFromRay(
                    ray,
                    intersection,
                    hitTriangle,
                    COLLIDE,
                    0);
    if (!selectedSceneNode || (!_collide && selectedSceneNode->getID() & EXPLODE)) {
        take_buff(pos);
        _textureNode->setPosition(pos);
    }
}

void Player::take_buff(core::vector3df detect)
{
    core::line3d<f32> ray;
    ray.start = _textureNode->getPosition();
    ray.end = detect;
    core::vector3df intersection;
    core::triangle3df hitTriangle;
    scene::ISceneCollisionManager* collMan = _grhdl->smgr->getSceneCollisionManager();
    scene::ISceneNode * powerNode =
            collMan->getSceneNodeAndCollisionPointFromRay(
                    ray,
                    intersection,
                    hitTriangle,
                    POWERUP,
                    0);
    if (powerNode)
    {
        if (powerNode->getID() & BOMBUP) {
            _bombStock += 1;
            _bomb->push_back(nullptr);
            buffs->bomb += 1;
        }
        if (powerNode->getID() & FIREUP) {
            _bombSpreading += 2.0f;
            buffs->spread += 1;
        }
        if (powerNode->getID() & SPEEDUP) {
            if (_speed <= 0.9f) {
                _speed += 0.1f;
                buffs->speed += 1;
            }
        }
        if (powerNode->getID() & WALLPASS) {
            _collide = false;
            buffs->wallpass = true;
        }
        _grhdl->smgr->addToDeletionQueue(powerNode);
    }
}

void Player::blow_up(uint player_id)
{
    if (player_id == _id)
        std::cout << "Player " << _id << " made a mistake.\n";
    else
        std::cout << "Player " << player_id << " blows Player " << _id << " up\n";
    if (_lives > 0)
        _lives -= 1;
    if (_lives == 0)
    {
        _grhdl->smgr->addToDeletionQueue(_textureNode);
        _alive = false;
    }

}

float Player::get_bombSpreading() { return (this->_bombSpreading); }

core::vector3df Player::get_position() { return (_textureNode->getPosition()); }

scene::IAnimatedMeshSceneNode *Player::get_node() { return (_textureNode); }

void Player::set_control(struct playerControl_s controls)
{
    _controls = controls;
}

uint Player::get_id() { return (_id); }

bool Player::is_alive() { return (_alive); }

void Player::play_sound()
{
    std::string dir = PROJECT_DIR;

    if (!_buffer.loadFromFile(std::string(dir + "/assets/sound/explosion.wav")))
        std::cerr << "Error while loading sound.\n";
    _sound = sf::Sound();
    _sound.setBuffer(_buffer);
    _sound.setVolume(70.0f);
    _sound.setAttenuation(0);
    _sound.setPosition(0, 0, 0);
}

struct buffs_t *Player::get_buffs()
{
    buffs->lives = _lives;
    return (this->buffs);
}