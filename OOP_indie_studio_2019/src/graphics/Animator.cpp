/*
** EPITECH PROJECT, 2019
** Animator.cpp
** File description:
** 
*/

#include "graphics/Animator.hpp"

Animator::Animator(graph_handler_t *grhdl, core::vector3df pos) : _start(NOW)
{
    this->_grhdl = grhdl;
    create_anim(pos);
}

Animator::~Animator() {}

void Animator::create_anim(core::vector3df pos)
{
     std::string path = PROJECT_DIR;

    
    scene::IParticleSystemSceneNode* ps =
        _grhdl->smgr->addParticleSystemSceneNode(false, 0, ANIMATION);
    scene::IParticleEmitter* em = ps->createBoxEmitter(
        core::aabbox3d<f32>(-2,0, -2, 2, 1,2),//core::aabbox3d<f32>(-7,0,-7,7,1,7), // emitter size
        core::vector3df(0.0f,0.01f,0.0f),   // initial direction
        80,100,                             // emit rate
        video::SColor(0,255,255,255),       // darkest color
        video::SColor(0,255,255,255),       // brightest color
        600,610,0,                         // min and max age, angle
        core::dimension2df(1.f,1.f),         // min size
        core::dimension2df(1.5f,1.5f));        // max size

    ps->setEmitter(em); // this grabs the emitter
    em->drop(); // so we can drop it here without deleting it

    scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

    ps->addAffector(paf); // same goes for the affector
    paf->drop();

    ps->setPosition(pos);
    ps->setScale(core::vector3df(0.5f));
    ps->setMaterialFlag(video::EMF_LIGHTING, false);
    ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    video::ITexture * texture = _grhdl->driver->getTexture(std::string(path + "/assets/fire.bmp").c_str());
    ps->setMaterialTexture(0, texture);
    ps->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
     scene::IVolumeLightSceneNode * n = _grhdl->smgr->addVolumeLightSceneNode(0, -1,
                32,                              // Subdivisions on U axis
                32,                              // Subdivisions on V axis
                video::SColor(0, 255, 255, 255), // foot color
                video::SColor(0, 0, 0, 0));      // tail color
    n->setScale(core::vector3df(56.0f, 56.0f, 56.0f));
    n->setPosition(core::vector3df(-120,50,40));
    core::array<video::ITexture*> textures;
    textures.push_back(texture);
    scene::ISceneNodeAnimator* glow = _grhdl->smgr->createTextureAnimator(textures, 150, false);

    // add the animator
    n->addAnimator(glow);
    glow->drop();
    _anim = ps;
}

bool Animator::update()
{
   if (DURATION<MILLISECONDS>(NOW - _start).count() > ANIM_DURATION_MS)
   {
       _anim->remove();
       return (true);
   }
   return (false);
} 