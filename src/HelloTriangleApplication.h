//
// Created by philipp on 16.07.17.
//

#ifndef VULKANVOXEL_HELLOTRIANGLEAPPLICATION_H
#define VULKANVOXEL_HELLOTRIANGLEAPPLICATION_H

//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>

class HelloTriangleApplication {
public:
    void run();
private:
    const int WIDTH = 800;
    const int HEIGHT = 600;

    void initWindow();
    void initVulkan();
    void createInstance();
    void mainLoop();
    void cleanup();

    GLFWwindow *window;
    VkInstance instance;
};


#endif //VULKANVOXEL_HELLOTRIANGLEAPPLICATION_H
