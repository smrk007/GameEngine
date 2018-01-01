//
//  Object.hpp
//  GameEngine
//
//  Created by Sean Michael Ritschard Kennedy on 1/1/18.
//  Copyright © 2018 skware. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>

#include "common.h"
#include "Util.hpp"

class Object
{
private:
    // Information for Simulation
    Vec pos;
    Vec vel;
    
    // Information for OpenGL
    GLushort offset;
    GLuint vertSize;
    GLfloat* verts;
    GLuint indxSize;
    GLushort* indices;
public:
    
    
    /* Graphics */
    // Initialization Functions
    void generate();
    void generateNVerts(GLfloat verts[], Color color, GLuint N, GLdouble r, Vec pos);
    void generateNIndices(GLushort indices[], GLuint N, GLuint offset);
    
    // Accessors
    std::size_t getVertByteSize() const { return sizeof(GLfloat) * vertSize; }
    std::size_t getIndxByteSize() const { return sizeof(GLushort) * indxSize; }
    GLfloat* getVertDataPointer() { return verts; }
    GLushort* getIndxDataPointer() { return indices; }
    // GLushort getIndxCount() { return N + 1; } // Specifically Applicable for NGons
    
};

#endif /* Object_hpp */
