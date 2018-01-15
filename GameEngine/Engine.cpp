#include "Engine.hpp"

void Engine::draw()
{
    // Handles the necessary elements of the window API
    window.clear();
    
    for (NGon object : objects)
    {
        window.draw(object);
    }
    
    window.display();
}

void Engine::update(GLdouble dt)
{
    for (NGon object : objects)
    {
        object.setPos(Vec(0,0,0));
    }
}
