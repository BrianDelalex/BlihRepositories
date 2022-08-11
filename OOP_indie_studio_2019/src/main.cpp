#include "platform.hpp"
#include "graphics/graphics.hpp"
#include "game_components/Map.hpp"
#include "game_components/Player.hpp"
#include "game_components/IA.hpp"
#include "game_components/playerRegistry.hpp"
#include "game_components/playerControl.hpp"
#include "graphics/Animator.hpp"
#include "menu/menuElements.hpp"

struct playerRegistry_s *registry;
std::list<Animator *> *animators;

int main(void)
{
    // std::string map_path = PROJECT_DIR;
     graph_handler_t *grhdl = init_graphics();
    // Map *map;
    // // Player *ply;
    // // Player *ply2;
    // std::string meshPath = PROJECT_DIR;
    // std::string textPath = PROJECT_DIR;
    // std::string text2Path = PROJECT_DIR;

    // animators = new std::list<Animator *>;
     menuElements *menu = new menuElements(grhdl);
    // std::srand(time(NULL));
    menu->initScene();
    // registry = playerRegistry_init();
    // map_path.append("/assets/maps/map.txt");
    // map = new Map(grhdl, map_path, 15, 15);
    // std::vector<Player *> *ply = create_player(2, grhdl, map);
    // std::vector<IA *> *ias = create_IA(2, 2, grhdl, map);
    // // ply = new Player(grhdl, map, 0, map->get_pos(0));
    // // ply->set_control(playerControl_create(irr::KEY_KEY_Z, irr::KEY_KEY_S, \
    irr::KEY_KEY_D, irr::KEY_KEY_Q, irr::KEY_SPACE));
    // // playerRegistry_add_player(registry, ply);
    // // ply2 = new Player(grhdl, map, 1, map->get_pos(1));
    // // ply2->set_control(playerControl_create(irr::KEY_UP, irr::KEY_DOWN, \
     irr::KEY_RIGHT, irr::KEY_LEFT, irr::KEY_KEY_M));
    // // playerRegistry_add_player(registry, ply2);

    // // meshPath.append("/assets/Bomberman.MD3");
    // // textPath.append("/assets/WhiteBombermanTextures.png");
    // // text2Path.append("/assets/PinkBombermanTextures.png");
    // // ply->init(meshPath, textPath);
    // // ply2->init(meshPath, text2Path);
    // draw_window(grhdl, ply, ias);
}
