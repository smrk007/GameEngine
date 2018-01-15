#include "Engine.hpp"

void Engine::draw()
{
    // Handles the necessary elements of the window API
    
    window.clear();
    for (NGon* object : objects)
    {
        window.draw(object);
    }
    window.display();
    for (NGon* object : objects)
    {
        object->clearData();
    }
}

void Engine::update(GLdouble dt)
{
    for (NGon* object : objects)
    {
        object->update(dt);
    }
}

void Engine::addObject(NGon* object)
{
    object->setTargetWindow(window.getWindow());
    objects.push_back(object);
}
