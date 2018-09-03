#ifndef INPUT_HANDLER_H_
#define INPUT_HANDLER_H_

#include "Window.h"

class InputHandler
{
private:
    GLFWwindow* m_window;
    
public:
    InputHandler();
    ~InputHandler() = default;

    void setWindow(GLFWwindow* window) { m_window = window; };
};

#endif // INPUT_HANDLER_H_