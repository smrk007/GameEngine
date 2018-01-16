//
//  Object.cpp
//  GameEngine
//
//  Created by Sean Michael Ritschard Kennedy on 1/13/18.
//  Copyright © 2018 skware. All rights reserved.
//

#include "Object.hpp"

void Object::update(GLdouble dt)
{
    Vec thisPos = pos;
    std::cout << dt << std::endl;
    Vec newPos = add(pos, scalarMultiply(vel,dt));
    
    setPos(newPos);
    
}

void Object::clearData()
{
    delete verts;
    delete indices;
}
