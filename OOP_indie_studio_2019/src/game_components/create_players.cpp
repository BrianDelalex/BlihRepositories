#include "game_components/Player.hpp"
#include "game_components/IA.hpp"
#include "game_components/playerControl.hpp"

extern struct playerRegistry_s *registry;

struct playerControl_s controls[] = { \
{irr::KEY_KEY_Z, irr::KEY_KEY_S, irr::KEY_KEY_D, irr::KEY_KEY_Q, irr::KEY_KEY_E}, \
{irr::KEY_UP, irr::KEY_DOWN, irr::KEY_RIGHT, irr::KEY_LEFT, irr::KEY_KEY_M}, \
{irr::KEY_KEY_F, irr::KEY_KEY_V, irr::KEY_KEY_B, irr::KEY_KEY_C, irr::KEY_KEY_G}, \
{irr::KEY_KEY_I, irr::KEY_KEY_K, irr::KEY_KEY_L, irr::KEY_KEY_J, irr::KEY_KEY_O} \
};

const char *textures[] = { \
"/assets/char/WhiteBombermanTextures.png", \
"/assets/char/PinkBombermanTextures.png", \
"/assets/char/BlackBombermanTextures.png", \
"/assets/char/RedBombermanTextures.png" \
};

std::vector<Player *> *create_player(uint nbPlayer, graph_handler_t *grhdl, \
Map *map)
{
    std::vector<Player *> *players;
    std::string dir = PROJECT_DIR;
    Player *ply;

    if ( nbPlayer > 4) {
        std::cerr << "Can't create more than four players.\n";
        return (nullptr);
    }
    players = new std::vector<Player *>;
    if (players == nullptr) {
        std::cerr << "New failed unable to allocate memory.\n";
        return (nullptr);
    }
    for (int i = 0; i < nbPlayer; i++) {
        ply = new Player(grhdl, map, i, map->get_pos(i));
        if (ply == nullptr) {
            std::cerr << "New failed unable to allocate memory.\n";
            return (nullptr);
        }
        ply->set_control(controls[i]);
        playerRegistry_add_player(registry, ply);
        ply->init(std::string(dir + "/assets/char/Bomberman.MD3"), \
        std::string(dir + textures[i]));
        players->push_back(ply);
    }
    return (players);
}

std::vector<IA *> *create_IA(uint nbPlayer, uint nbIA, graph_handler_t *grhdl, \
Map *map)
{
    std::vector<IA *> *ias;
    std::string dir = PROJECT_DIR;
    IA *ia;

    if (nbIA > 4 || nbIA + nbPlayer > 4) {
        std::cerr << "Can't create more than four players or IA.\n";
        return (nullptr);
    }
    ias = new std::vector<IA *>;
    if (ias == nullptr) {
        std::cerr << "New failed unable to allocate memory.\n";
        return (nullptr);
    }
    for (uint i = 0; i < nbIA; i++) {
        ia = new IA(grhdl, map, (i + nbPlayer), map->get_pos(i + nbPlayer));
        if (ia == nullptr) {
            std::cerr << "New failed unable to allocate memory.\n";
            return (nullptr);
        }
        playerRegistry_add_player(registry, ia);
        ia->init(std::string(dir + "/assets/char/Bomberman.MD3"), \
        std::string(dir + textures[i + nbPlayer]));
        ias->push_back(ia);
    }
    return (ias);
}