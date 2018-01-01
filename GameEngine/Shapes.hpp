#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>

#include "common.h"
#include "Object.hpp"
#include "Util.hpp"

class NGon
{
private:
    // Characteristics
    GLuint N;
    GLdouble radius;
    Vec pos;
    Color color = Color(1,1,1,1);
    
    // Info for OpenGL
    GLushort offset;
    GLuint vertSize;
    GLfloat* verts;
    GLuint indxSize;
    GLushort* indices;
public:
    NGon(GLuint newN, GLdouble newRadius, Vec newPos)
    {
        N = newN;
        radius = newRadius;
        pos = newPos;
    }
    
    // Accessors
    std::size_t getVertByteSize() const { return sizeof(GLfloat) * vertSize; }
    std::size_t getIndxByteSize() const { return sizeof(GLushort) * indxSize; }
    GLfloat* getVertDataPointer() { return verts; }
    GLushort* getIndxDataPointer() { return indices; }
    GLushort getIndxCount() { return vertSize / 7; } // TODO: Find a way to generalize the Magic Number 7 (datapoints per vertex)
    
    // Mutators
    void setColor(Color newColor) { color = newColor; }
    void setOffset(GLushort newOffset) { offset = newOffset; }
    void setPos(Vec newPos) { pos = newPos; }
    void setRadius(GLdouble newRadius) { radius = newRadius; }
    void setSideCount(GLuint newN) { N = newN; }
    
    // Initialization Functions
    void generate();
    void generateNVerts(GLfloat verts[], Color color, GLuint N, GLdouble r, Vec pos);
    void generateNIndices(GLushort indices[], GLuint N, GLuint offset);
};

#endif /* Shapes_hpp */
