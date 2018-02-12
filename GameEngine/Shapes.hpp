#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>

#include "common.h"
#include "Object.hpp"
#include "Util.hpp"

class NGon : public Object
{
public:
    NGon(GLuint newN, GLdouble newRadius, Vec newPos)
    {
        N = newN;
        radius = newRadius;
        pos = newPos;
        vel = Vec(0,0,0);
        facing = Vec(0.7071067812,0,-0.7071067812); // Facing camera by default
    }
    
    void update(GLdouble dt);
    void factorControls();
    
    // Initialization Functions
    void generate() override;
    void generateNVerts(Vertex* verts, Color color, GLuint N, GLdouble r, Vec pos) override;
    void generateNIndices(GLushort* indices, GLuint N, GLuint offset) override;
};

class Cube : public Object
{
  //
};

#endif /* Shapes_hpp */
