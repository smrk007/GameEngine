#ifndef Engine_hpp
#define Engine_hpp

#include <stdio.h>

#include "common.h"
#include "Window.hpp"

class Engine
{
public:
    Window window;
    std::vector<NGon*> objects; // TODO: Create an Object class
public:
    Engine()
    {
        
    }
    ~Engine()
    {
        for (Object* object : objects)
        {
            delete object;
        }
        objects.clear();
    }
    
    // Accessors
    bool isRunning() { return window.isOpen(); } // TODO: Think of different ways of how the engine could close
    
    // Simulation
    void addObject(NGon* object);
    void update(GLdouble dt);
    
    // Graphics
    void draw();
};

#endif /* Engine_hpp */
