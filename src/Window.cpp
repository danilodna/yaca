#include "Window.h"

static void error_callback(int error, const char* description);
static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Window::Window(std::string title, int width, int height)
{
    m_title = title;
    m_width = width;
    m_height = height;

    glfwSetErrorCallback(error_callback);

    if(init() == -1) exit(EXIT_FAILURE);
    if(config() == -1) exit(EXIT_FAILURE);
    
}

int Window::init()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    } 
    else 
    {
        return 0;
    }
}

int Window::config()
{
    glfwMakeContextCurrent(m_window);

    // This function defines the callback which will be called everytime that the window is resized,
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    // These functions defines the callback for these forms of input.
    glfwSetKeyCallback(m_window, key_callback);
    glfwSetMouseButtonCallback(m_window, mouse_button_callback);
    glfwSetCursorPosCallback(m_window, cursor_pos_callback);
    glfwSetScrollCallback(m_window, scroll_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 
    else 
    {
        return 0;           
    }
}

bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_window);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::cleanAndDestroyWindow()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
static void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    // if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    //     popup_menu();
}

// The callback functions receives the cursor position, measured in screen coordinates but 
// Relative to the top-left corner of the window client area
static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
}

static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}