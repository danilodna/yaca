#ifndef SHADER_H_
#define SHADER_H_

#include "Window.h"

class Shader
{
private:
    int m_id;    

public:
    Shader() = default;
    ~Shader() = default;

    int getID() { return m_id; };
    int setID(const int id) { m_id = id; };

    void compile(const GLchar* vertex, const GLchar* fragment, const GLchar* geometry = NULL);
    Shader use();
};

#endif // SHADER_H_
