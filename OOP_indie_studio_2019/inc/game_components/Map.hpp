/*
** EPITECH PROJECT, 2019
** Map.hpp
** File description:
** 
*/

#ifndef MAP_HPP_
#define MAP_HPP_

# include <iostream>

# include "graphics/graphics.hpp"
# include "utils/utils.hpp"

class Map
{
public:
    Map(graph_handler_t *grhdl, std::string file_path, int width, int height);
    ~Map();
    bool check_pos(const core::vector3df pos);
    core::vector3df get_pos(int id);
private:
    void get_player_pos();
    graph_handler_t *_grhdl;
    scene::IMesh *_plan;
    const scene::IGeometryCreator* _geoCreator;
    std::vector<std::string> *_mapTxt;
    IMeshVec *_mapMesh;
    video::SMaterial *_floor; 
    const int _mapWidth;
    const int _mapHeight;
    std::vector<core::vector3df> _playersPos;
};

#endif
