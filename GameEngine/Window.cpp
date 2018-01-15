#include "Window.hpp"

void Window::display()
{
    /*
     Basically, this just handles everything after initializing the objects and adding them to the window
    */
    
    // General //////////
    glBufferData(GL_ARRAY_BUFFER, totalVertSize, NULL, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, totalIndxSize, NULL, GL_STATIC_DRAW);
    
    // Binding Individual Objects
    std::size_t vertIt = 0;
    std::size_t indxIt = 0;
    
    for (NGon* object : objects)
    {
        glBufferSubData(GL_ARRAY_BUFFER, vertIt, object->getVertByteSize(), object->getVertDataPointer());
        vertIt += object->getVertByteSize();
        
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, indxIt, object->getIndxByteSize(), object->getIndxDataPointer());
        indxIt += object->getIndxByteSize();
    }
     
    glUseProgram(programID);
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, 0); // Position
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (char*)(sizeof(GLfloat) * 3)); // Color
    glDrawElements(GL_TRIANGLES, boundVertices, GL_UNSIGNED_SHORT, 0);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::draw(NGon* object)
{
    /*
     Provides the offset information to the object and initlializes it, then adds the object to the objects vector
    */
    
    object->setOffset(currentOffset);
    object->generate();
    currentOffset += object->getIndxCount();
    objects.push_back(object);
    totalVertSize += object->getVertByteSize();
    totalIndxSize += object->getIndxByteSize();
    boundVertices += object->getIndxByteSize() / sizeof(GLushort);
}

void Window::clear()
{
    /*
     Sets up the window for a new drawing call
    */
    
    currentOffset = 0;
    boundVertices = 0;
    totalVertSize = 0;
    totalIndxSize = 0;
    objects.clear();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Operations for Transparency and Depth
    // glEnable(GL_DEPTH_TEST); // Enables Depth, but Harder for Alpha and Transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool Window::isOpen()
{
    return glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0;
}

Window::Window()
{
    /*
     Creates a window and loads the shaders
     Handles everything for initialization
    */
    
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW\n");
        exit(1);
    }
    
    // Initializing the Window
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL: 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Make MacOS Happy
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want old OpenGL
    
    // Create the window
    window = glfwCreateWindow(768, 768, "Window", NULL, NULL); // TODO: Come up with a better window name
    if (window == NULL)
    {
        printf("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        exit(1);
    }
    
    glewExperimental = true; // Needed in core profile
    glfwMakeContextCurrent(window); // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        printf("Failed to initialize GLEW.\n");
        exit(1);
    }
    
    // Ensure we can capture the escape key being pressed
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Initializing the VAO
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    // Create and compile our GLSL program from the shaders
    programID = loadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
    
    GLuint vertexBufferID;
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    
    GLuint indexBufferID;
    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
}

GLuint Window::loadShaders(const char * vertex_file_path, const char * fragment_file_path)
{
    /*
     Does all the shader loading and processing
    */
    
    // Create the Shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if (VertexShaderStream.is_open())
    {
        std::string Line = "";
        while (getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }else{
        printf("Impossible to open %s. Are you in the right directory? Don't forget to read the FAQ!\n", vertex_file_path);
        getchar();
        return 0;
    }
    
    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open())
    {
        std::string Line = "";
        while (getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }
    
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);
    
    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }
    
    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);
    
    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    }
    
    // Link the Program
    printf("Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
    
    // Check the Program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }
    
    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);
    
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
    
    return ProgramID;
}
