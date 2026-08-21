#include "eng.h"
#include <iostream>




namespace eng
{
    GLFWwindow* window;
    Camera camera(Vector3(0.0f, 0.0f, 0.0f));
    void init()
    {
        if(!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW." << std::endl;
            return;
        }
        std::cout << "Engine initialized." << std::endl;
    }

    void makewindow(int width, int height, const char* title)
    {
        // Create a window with the specified dimensions and title
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);


        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &width, &height);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
           std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwDestroyWindow(window);
            glfwTerminate();
            return;
        }


        glViewport(0, 0, width, height);
    }

    bool tick()
    {
        camera.UpdateCamera(Vector3(1.0f, 0.0f, 0.0f), "cameraPos", 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
        return !glfwWindowShouldClose(window);
    }
    

}
