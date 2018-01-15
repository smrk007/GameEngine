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
    Vec newPos = pos.add(vel);
    
    setPos(newPos);
    
}

void Object::clearData()
{
    delete verts;
    delete indices;
}
