#include "Shader.h"

void Shader::compile(const GLchar* vSource, const GLchar* fSource, const GLchar* gSource)
{
    //  Vertex Shader
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, NULL);
    glCompileShader(vShader);

    // Fragment Shader
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, NULL);
    glCompileShader(fShader);

    // Attach Shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vShader);
    glAttachShader(shaderProgram, fShader);

    // Geometry Shader
    if(gSource != NULL)
    {
        GLuint gShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(gShader, 1, &gSource, NULL);
        glCompileShader(gShader);
        glAttachShader(shaderProgram, gShader);
    
        glLinkProgram(shaderProgram);
        
        glDeleteShader(vShader);
        glDeleteShader(fShader);
        glDeleteShader(gShader);
    }
    else
    {
        glLinkProgram(shaderProgram);
        
        glDeleteShader(vShader);
        glDeleteShader(fShader);
    }

}

