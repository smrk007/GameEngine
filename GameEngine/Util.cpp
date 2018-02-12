#include "Util.hpp"

// TODO: Test this stuff

Vec add (Vec v, Vec u)
{
    return Vec(v.x + u.x, v.y + u.y, v.z + u.z);
}

Vec subtract (Vec v, Vec u)
{
    return Vec(v.x - u.x, v.y - u.y, v.z - u.z);
}

Vec scalarMultiply (Vec v, GLdouble s)
{
    return Vec(v.x * s, v.y * s, v.z * s);
}

Vec scalarDivide (Vec v, GLdouble s)
{
    return Vec(v.x / s, v.y / s, v.z / s);
}

GLdouble dotProduct (Vec v, Vec u)
{
    return (v.x * u.x) + (v.y * u.y) + (v.z * u.z);
}

Vec crossProduct (Vec v, Vec u)
{
    GLdouble x = (u.y * v.z) - (u.z * v.y);
    GLdouble y = (v.x * u.z) - (u.x * v.z);
    GLdouble z = (u.x * v.y) - (v.x * u.y);
    return Vec(x,y,z);
}

GLdouble length (Vec v)
{
    return sqrt( (v.x * v.x) + (v.y * v.y) + (v.z * v.z) );
}

Vec unitVector (Vec v)
{
    GLdouble L = length(v);
    return Vec(v.x / L, v.y / L, v.z / L);
}

double angle(Vec v, Vec u)
{
    return acos( dotProduct(v,u) / (length(v) * length(u)) );
}
