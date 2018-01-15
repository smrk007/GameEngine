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
        vel = Vec(0.1,0,0);
    }
    
    void update(GLdouble dt);
    
    // Initialization Functions
    void generate() override;
    void generateNVerts(GLfloat verts[], Color color, GLuint N, GLdouble r, Vec pos) override;
    void generateNIndices(GLushort indices[], GLuint N, GLuint offset) override;
};

#endif /* Shapes_hpp */
