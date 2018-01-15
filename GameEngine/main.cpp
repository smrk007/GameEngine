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
    world.addObject(new NGon(20,0.1,Vec(0.5,0.2,0)));

    do {
        world.draw();
        world.update(1);
    }
    while (world.isRunning());

    return 0;
}
