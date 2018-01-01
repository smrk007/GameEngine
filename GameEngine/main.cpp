#include "Window.hpp"

#include <iostream>

#include "Engine.hpp"
#include "Util.hpp"

int main() {
    
    /*
     TASKS
     
     TODO: Create an Object Class
     TODO: Create an Update System
     TODO: Add dt to the main loop
     
    */
    
    Engine world;
    world.addObject(NGon(3,0.3,Vec(0.5,0.2,0)));
    world.addObject(NGon(4,0.5,Vec(-0.2,-0.1,0)));
    
    do {
        world.draw();
    }
    while (world.isRunning());

    return 0;
}
