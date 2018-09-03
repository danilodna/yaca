#ifndef WINDOW_H_
#define WINDOW_H_

#include "../dependencies/glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

class Window
{
private:
    GLFWwindow* m_window;
    std::string m_title;
    int m_width;
    int m_height;
    int init();
    int config();

public:
    Window() = default;
    ~Window() = default;

    void setWidth(int width) { m_width = width; };
    void setHeight(int height) { m_height = height; };
    int getWidth() const { return m_width; };
    int getHeight() const { return m_height; };

    Window(std::string title, int width = 800, int height = 600);
    GLFWwindow* getWindow() const { return m_window; };

    bool isOpen();
    void clear();
    void update();
    void cleanAndDestroyWindow();
};

#endif // WINDOW_H_