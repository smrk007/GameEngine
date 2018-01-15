#ifndef Window_hpp
#define Window_hpp

#include "common.h"
#include "Shapes.hpp"

class Window
{
private:
    GLFWwindow* window;
    GLuint programID;
    GLuint VertexArrayID;
    GLuint vertexbuffer;
    
    std::vector<NGon*> objects;
    
    GLushort currentOffset;
    GLuint boundVertices;
    std::size_t totalVertSize;
    std::size_t totalIndxSize;
public:
    Window();
    ~Window()
    {
        // TODO: I think that OpenGL handles the GLFW window...?
    }
public:
    GLFWwindow* getWindow() { return window; }
    void clear();
    void display();
    void draw(NGon* shape);
    bool isOpen();
    GLuint loadShaders (const char* vertex_file_path, const char * fragment_file_path);
};

#endif /* Window_hpp */
