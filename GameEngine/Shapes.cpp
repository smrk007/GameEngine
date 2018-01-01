#include "Shapes.hpp"

void NGon::generate()
{
    // Declare the Vertex and Indice arrays
    vertSize = (N + 1) * 7;
    indxSize = N * 3;
    verts = new GLfloat[vertSize];
    indices = new GLushort[indxSize];
    
    // Initialize the Vertex and Indice arrays
    generateNVerts(verts, color, N, radius, pos);
    generateNIndices(indices, N, offset);
}

void NGon::generateNVerts(GLfloat verts[], Color color, GLuint N, GLdouble r, Vec pos)
{
    /*
     Generates an array for the GL_ARRAY_BUFFER binding point
    */
     
    const GLdouble RADIANS_PER_SLICE = 6.283185 / N;
    
    // Initializing Center Point
    verts[0] = pos.x;
    verts[1] = pos.y;
    verts[2] = pos.z;
    verts[3] = color.red;
    verts[4] = color.green;
    verts[5] = color.blue;
    verts[6] = color.alpha;
    
    // Initializing Edge Points
    for (int i = 1; i <= N; i++)
    {
        verts[i*7+0] = pos.x + sin(RADIANS_PER_SLICE * i) * r; // X
        verts[i*7+1] = pos.y + cos(RADIANS_PER_SLICE * i) * r; // Y
        verts[i*7+2] = pos.z;                                  // Z
        
        verts[i*7+3] = color.red;                              // R
        verts[i*7+4] = color.green;                            // G
        verts[i*7+5] = color.blue;                             // B
        verts[i*7+6] = color.alpha;                            // A
    }
}

void NGon::generateNIndices(GLushort indices[], GLuint N, GLuint offset)
{
    /*
     Generates the element array for the GL_ELEMENT_ARRAY binding point
    */
    
    // Offset is the amount of offset due to the number of indices
    for (int i = 0; i < N; i++)
    {
        indices[i*3] = 0 + offset;
        indices[i*3+1] = i + 1 + offset;
        indices[i*3+2] = (i+1)%N + 1 + offset;
    }
}

