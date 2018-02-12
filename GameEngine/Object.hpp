//
//  Object.hpp
//  GameEngine
//
//  Created by Sean Michael Ritschard Kennedy on 1/13/18.
//  Copyright © 2018 skware. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>

#include "common.h"
#include "Util.hpp"

struct Object
{
    // General Information
    GLuint N;
    GLdouble radius;
    Vec pos;
    Vec vel;
    Vec facing;
    GLFWwindow* targetWindow;
    
    void setTargetWindow(GLFWwindow* window) { targetWindow = window; }
    
    void setFacing(Vec newFacing) { facing = unitVector(newFacing); }
    
    // Physics ///////////////////////////////////////
    void update(GLdouble dt);
    //////////////////////////////////////////////////
    
    // Graphics //////////////////////////////////////
    // Model Information
    Color color = Color(1.0,0,0.0,1);
    // Info for OpenGL
    GLushort offset;
    GLuint vertSize;
    Vertex* verts = nullptr;
    GLuint indxSize;
    GLushort* indices = nullptr;
    // Accessor Functions
    std::size_t getVertByteSize() const { return sizeof(Vertex) * vertSize; }
    std::size_t getIndxByteSize() const { return sizeof(GLushort) * indxSize; }
    Vertex* getVertDataPointer() { return verts; }
    GLushort* getIndxDataPointer() { return indices; }
    GLushort getIndxCount() { return vertSize / 7; } // TODO: Find a way to generalize the Magic Number 7 (datapoints per vertex)
    // Mutator Functions
    void setColor(Color newColor) { color = newColor; }
    void setOffset(GLushort newOffset) { offset = newOffset; }
    void setPos(Vec newPos) { pos = newPos; }
    void setRadius(GLdouble newRadius) { radius = newRadius; }
    void setSideCount(GLuint newN) { N = newN; }
    // Model Generation Functions
    virtual void generate() = 0;
    virtual void generateNVerts(Vertex verts[], Color color, GLuint N, GLdouble r, Vec pos) = 0;
    virtual void generateNIndices(GLushort indices[], GLuint N, GLuint offset) = 0;
    void clearData();
    //////////////////////////////////////////////////
};

#endif /* Object_hpp */
