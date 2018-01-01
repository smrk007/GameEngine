#include "Window.hpp"

#include <iostream>
#include "Util.hpp"

int main() {
    
    Window window;
    
    std::vector<NGon> objects;
    objects.push_back(NGon(3,0.3,Vec(0.5,0.2,0)));
    objects.push_back(NGon(4,0.5,Vec(-0.2,-0.1,0)));
    
    do {
        window.clear();
        
        for (NGon object : objects) {
            window.draw(object);
        }
        
        window.display();
    }
    while(window.isOpen());

    return 0;
}
