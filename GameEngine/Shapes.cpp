#include "Shapes.hpp"

void NGon::generate()
{
    // Declare the Vertex and Indice arrays
    vertSize = (N + 1) * 7;
    indxSize = N * 3;
    
    verts = new Vertex[vertSize];
    indices = new GLushort[indxSize];
    
    // Initialize the Vertex and Indice arrays
    generateNVerts(verts, color, N, radius, pos);
    generateNIndices(indices, N, offset);
}

void NGon::generateNVerts(Vertex* verts, Color color, GLuint N, GLdouble r, Vec pos)
{
    /*
     Generates an array for the GL_ARRAY_BUFFER binding point
    */
     
    const GLdouble RADIANS_PER_SLICE = 6.283185 / N;
    
    // Initializing Center Point
    verts[0].position = glm::vec3(pos.x, pos.y, pos.z);
    verts[0].color = glm::vec4(color.red, color.green, color.blue, color.alpha);

    // Initializing Edge Points
    for (int i = 1; i <= N; i++)
    {
        verts[i].position = glm::vec3(pos.x + sin(RADIANS_PER_SLICE * i) * r,
                                      pos.y + cos(RADIANS_PER_SLICE * i) * r,
                                      pos.z);
        // Performing Rotation
        // Part 1: Finding Angle of Rotation
        double thisAngle = angle(Vec(0,0,-1), Vec(facing.x,0,facing.z));
        // Part 2: Performing Rotation Based on Angle
        verts[i].position.x = cos(thisAngle)*verts[i].position.x - sin(thisAngle)*verts[i].position.z;
        verts[i].position.z = cos(thisAngle)*verts[i].position.z + sin(thisAngle)*verts[i].position.x;
       
        verts[i].color.r = color.red;                              // R
        verts[i].color.g = color.green;                            // G
        verts[i].color.b = color.blue;                             // B
        verts[i].color.a = color.alpha;                            // A
    }
}

void NGon::generateNIndices(GLushort* indices, GLuint N, GLuint offset)
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

void NGon::update(GLdouble dt)
{
    factorControls();
    
    setPos(add(pos, scalarMultiply(vel,dt)));
}

void NGon::factorControls()
{
    if (glfwGetKey(targetWindow, GLFW_KEY_UP) == GLFW_PRESS)
    {
        vel = Vec(0,0.003,0);
    }
    else if (glfwGetKey(targetWindow, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        vel = Vec(0,-0.003,0);
    }
    else if (glfwGetKey(targetWindow, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        vel = Vec(-0.003,0,0);
    }
    else if (glfwGetKey(targetWindow, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        vel = Vec(0.003,0,0);
    }
    else
    {
        vel = Vec(0,0,0);
    }
}

