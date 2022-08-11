/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <graphics/graphics.hpp>
#include <utils/utils.hpp>

IMeshVec *create_map(graph_handler_t *gr_hdl, irr::scene::IMesh *plan, \
int width, int height, std::vector<std::string> *map)
{
    std::string path = std::string(PROJECT_DIR);
    std::string texturePath = PROJECT_DIR;

    //path.append("/assets/Crate/Crate1.obj");
    texturePath.append("/assets/Crate/crate_1.jpg");
    irr::scene::IAnimatedMesh* mesh = gr_hdl->smgr->getMesh(std::string(path + "/assets/Crate/Crate1.obj").c_str());
    if (!mesh)
    {
        gr_hdl->device->drop();
        std::cerr << "Error loading mesh: create_map.cpp l.16" << std::endl;
        return NULL;
    }
    //IMeshVec *crates = new IMeshVec;
    int startX = - width + 1;
    int startZ = height - 1;
    irr::scene::IMeshSceneNode* node;
    for (int i = 0; i < (int) map->size(); i++)
    {
        for (int j = 0; j < (int) (*map)[i].length() ; j++)
        {
            if ((*map)[i][j] == 'X')
            {
                node = gr_hdl->smgr->addMeshSceneNode( mesh, 0, COLLIDE | EXPLODE );
                if (node)
                {
                    scene::ITriangleSelector* selector = gr_hdl->smgr->createTriangleSelector(mesh, node);
                    if (selector == NULL)
                        std::cout << "WARNING: NULL SELECTOR" << std::endl;
                    node->setTriangleSelector(selector);
                    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    node->setMaterialTexture( 0, gr_hdl->driver->getTexture( texturePath.c_str() ) );
                    selector->drop();
                }
                irr::core::vector3df pos = plan->getBoundingBox().getCenter();
                irr::core::vector3d<irr::f32> *edges = new irr::core::vector3d<irr::f32>[8];
                mesh->getBoundingBox().getEdges(edges);
                pos.X = startX + (j * 2);
                pos.Z = startZ - (i * 2);
                pos.Y = pos.Y + ((edges[1].Y - edges[0].Y) / 2);
                node->setPosition(pos);
            }
            if ((*map)[i][j] == '#')
            {
                node = gr_hdl->smgr->addMeshSceneNode( mesh, 0, COLLIDE | NOEXPLODE);
                if (node)
                {
                    scene::ITriangleSelector* selector = gr_hdl->smgr->createTriangleSelector(mesh, node);
                    if (selector == NULL)
                        std::cout << "WARNING: NULL SELECTOR" << std::endl;
                    node->setTriangleSelector(selector);
                    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                    node->setMaterialTexture( 0, gr_hdl->driver->getTexture( std::string(path + "/assets/Crate/crate_2.jpg").c_str()));
                    selector->drop();
                }
                irr::core::vector3df pos = plan->getBoundingBox().getCenter();
                irr::core::vector3d<irr::f32> *edges = new irr::core::vector3d<irr::f32>[8];
                mesh->getBoundingBox().getEdges(edges);
                pos.X = startX + (j * 2);
                pos.Z = startZ - (i * 2);
                pos.Y = pos.Y + ((edges[1].Y - edges[0].Y) / 2);
                node->setPosition(pos);
            }
        }
    }
    return (nullptr);
}