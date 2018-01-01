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
