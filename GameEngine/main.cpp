#include <iostream>

#include "common.h"
#include "Engine.hpp"
#include "Util.hpp"
#include "Window.hpp"

#include <unistd.h> // Note: Mac Only

int main() {
    
    /*
     TASKS
     
     TODO: Create an Object Class
     TODO: Create an Update System
     TODO: Add dt to the main loop
     
    */
    
    Engine world;
    world.addObject(new NGon(12,1,Vec(0,0,0)));
    
    clock_t t = clock();
    clock_t dt;
    
    double x = 0;

    do {
        
        x += 0.05;
        world.draw();
        
        
        world.objects.at(0)->setFacing(Vec(cos(x),0,sin(x)));
        // world.objects.at(0)->setColor(Color(sin(0.50001*x),sin(0.95322*x),sin(0.83*x),1));
        /*
        dt = clock() - t;
        sleep(0.017);
        t = clock();
        std::cout << dt << std::endl;
        */
        
        
        // world.update(dt/200);
        
        
    }
    while (world.isRunning());

    return 0;
}
