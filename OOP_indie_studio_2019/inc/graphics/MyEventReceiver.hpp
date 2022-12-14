#include <irrlicht.h>

#ifndef EVENT_RECEIVER_HPP
#define EVENT_RECEVIER_HPP

class MyEventReceiver : public irr::IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const irr::SEvent& event)
    {
        // Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
        {
            if ((leftClickDown =  event.MouseInput.isLeftPressed())) {
                last_click.X = event.MouseInput.X;
                last_click.Y = event.MouseInput.Y;
            }
        
        }
        return false;
    }

    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
    {
        return KeyIsDown[keyCode];
    }

    virtual bool IsLeftKeyDown() const
    {
        return (leftClickDown);
    }

    virtual irr::core::vector2di getMousePos()
    {
        return (last_click);
    }
    
    MyEventReceiver()
    {
        for (irr::u32 i=0; i < irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
    bool leftClickDown;
    irr::core::vector2di last_click;
    
};

#endif