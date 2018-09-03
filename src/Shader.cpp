#include "Shader.h"

void Shader::compile(const GLchar* vSource, const GLchar* fSource, const GLchar* gSource)
{
    //  Vertex Shader
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, NULL);
    glCompileShader(vShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment Shader
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, NULL);
    glCompileShader(fShader);

    // check for shader compile errors
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

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

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    m_id = shaderProgram;
}

Shader Shader::use()
{
    glUseProgram(m_id);
    return *this;
}

