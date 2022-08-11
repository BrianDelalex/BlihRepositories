#include "game_components/powerUp.hpp"

void create_powerup(graph_handler_t *grhdl, POWER_UP power, core::vector3df pos)
{
    irr::s32 flags;
    std::string path = PROJECT_DIR;
    std::string textPath = PROJECT_DIR;

    if (power == BombUp)
    {
        flags = POWERUP | BOMBUP;
        textPath.append("/assets/powerup/BombUp.jpg");
    }
    if (power == FireUp)
    {
        flags = POWERUP | FIREUP;
        textPath.append("/assets/powerup/FireUp.jpg");
    }
    if (power == SpeedUp)
    {
        flags = POWERUP | SPEEDUP;
        textPath.append("/assets/powerup/SpeedUp.jpg");
    }
    if (power == WallPass)
    {
        flags = POWERUP | WALLPASS;
        textPath.append("/assets/powerup/WallPass.jpg");
    }
    irr::scene::IAnimatedMesh* mesh = grhdl->smgr->getMesh(std::string(path + "/assets/Crate/Crate1.obj").c_str());
    if (!mesh)
    {
        std::cerr << "Error loading mesh: create_powerup.cpp l.17" << std::endl;
        return;
    }
    irr::scene::IMeshSceneNode *node = grhdl->smgr->addMeshSceneNode( mesh, 0, flags);
    if (node)
    {
        scene::ITriangleSelector* selector = grhdl->smgr->createTriangleSelector(mesh, node);
        if (selector == NULL)
            std::cout << "WARNING: NULL SELECTOR" << std::endl;
        node->setTriangleSelector(selector);
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMaterialTexture( 0, grhdl->driver->getTexture( textPath.c_str() ) );
        node->setPosition(pos);
        selector->drop();
    }

}