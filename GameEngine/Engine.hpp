#ifndef Engine_hpp
#define Engine_hpp

#include <stdio.h>

#include "common.h"
#include "Window.hpp"

class Engine
{
private:
    Window window;
    std::vector<NGon> objects; // TODO: Create an Object class
public:
    Engine()
    {
        
    }
    ~Engine()
    {
        
    }
    
    // Accessors
    bool isRunning() { return window.isOpen(); } // TODO: Think of different ways of how the engine could close
    
    // Simulation
    void addObject(NGon object) { objects.push_back(object); }
    
    // Graphics
    void draw();
};

#endif /* Engine_hpp */
