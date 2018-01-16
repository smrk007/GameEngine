#include <iostream>

#include "common.h"
#include "Engine.hpp"
#include "Util.hpp"
#include "Window.hpp"

int main() {
    
    /*
     TASKS
     
     TODO: Create an Object Class
     TODO: Create an Update System
     TODO: Add dt to the main loop
     
    */
    
    Engine world;
    world.addObject(new NGon(20,0.1,Vec(0.5,0.2,0)));
    
    clock_t t = clock();
    clock_t dt;

    do {
        
        
        world.draw();
        
        dt = clock() - t;
        t = clock();
        
        std::cout << dt << std::endl;
        
        world.update(dt/1000);
        
        
    }
    while (world.isRunning());

    return 0;
}
