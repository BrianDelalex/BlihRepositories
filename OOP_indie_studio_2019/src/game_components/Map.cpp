/*
** EPITECH PROJECT, 2019
** Map.cpp
** File description:
** 
*/

#include "game_components/Map.hpp"

Map::Map(graph_handler_t *grhdl, std::string file_path, \
int width, int height) : _mapWidth(width), _mapHeight(height)
{
    int bitmap = bitmap & 0x00000000;
    bitmap = bitmap | GROUND;
    printf("mapid %08x\n", bitmap);
    this->_grhdl = grhdl;
    this->_geoCreator = grhdl->smgr->getGeometryCreator();
    _floor = new video::SMaterial();
    std::string path = PROJECT_DIR;
    path.append("/assets/floor.jpg");
    _floor->setTexture(0, grhdl->driver->getTexture(path.c_str()));
    _floor->setFlag(irr::video::EMF_LIGHTING, false);
    _plan = _geoCreator->createPlaneMesh(core::dimension2df(2, 2), \
    core::dimension2du(width, height), _floor, core::dimension2df(6, 6));
    _grhdl->smgr->addMeshSceneNode(_plan, 0, bitmap);
    _mapTxt = read_map_from_file(file_path);
    get_player_pos();
    _mapMesh = create_map(_grhdl, _plan, _mapWidth, _mapHeight, _mapTxt);
}

Map::~Map()
{
    delete _mapTxt;
}

bool Map::check_pos(const core::vector3df pos)
{
    int startX = - _mapWidth + 1;
    int startZ = _mapHeight - 1;
    int x = ((int)((pos.X - startX + 1) / 2));
    int y = ((int) ((startZ - pos.Z + 1) / 2));

    std::cout << "X: " << x << " Y: " << y << std::endl;
    if (x < 0 || x >= (int) (*_mapTxt)[0].length() || \
    y >= (int) _mapTxt->size() || y < 0)
        return (false);
    if ((*_mapTxt)[x][y] == '#')
        return (false);
    return (true);
}

void Map::get_player_pos()
{
    int startX = - _mapWidth + 1;
    int startZ = _mapHeight - 1;

    for (int i = 0; i < (int) _mapTxt->size(); i++) {
        for (int j = 0; j < (int) (*_mapTxt)[i].length(); j++)
        {
            if ((*_mapTxt)[i][j] == 'P')
            {
                core::vector3df pos;
                pos.X = startX + (j * 2);
                pos.Z = startZ - (i * 2);
                pos.Y = 0;
                _playersPos.push_back(pos);
            }
        }
    }
}

core::vector3df Map::get_pos(int id)
{
    if (id < _playersPos.size())
        return (_playersPos[id]);
    return (core::vector3df(0, 0, 0));
}