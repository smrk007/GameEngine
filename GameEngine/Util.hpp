#ifndef Util_hpp
#define Util_hpp

#include <stdio.h>

#include "common.h"

class Color
{
public:
    GLfloat red;
    GLfloat green;
    GLfloat blue;
    GLfloat alpha;
public:
    Color()
    {
        red = 0;
        green = 0;
        blue = 0;
        alpha = 0;
    }
    Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
    {
        red = r;
        green = g;
        blue = b;
        alpha = a;
    }
};

//////////////////////////////////////////////////

class Vec
{
public:
    GLfloat x;
    GLfloat y;
    GLfloat z;
public:
    Vec()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vec(GLfloat X, GLfloat Y, GLfloat Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
};

// Vector Math
Vec add (Vec v, Vec u);
Vec subtract (Vec v, Vec u);
Vec scalarMultiply (Vec v, GLdouble s);
Vec scalarDivide (Vec v, GLdouble s);
GLdouble dotProduct (Vec v, Vec u);
Vec crossProduct (Vec v, Vec u);
GLdouble length (Vec v);
Vec unitVector (Vec v);
double angle (Vec v, Vec u);

//////////////////////////////////////////////////

struct Vertex
{
    glm::vec3 position;
    glm::vec4 color;
};

#endif /* Util_hpp */
