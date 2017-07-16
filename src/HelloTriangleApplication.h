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
#include <vector>
#include <cstring>

class HelloTriangleApplication {
public:
    void run();
private:
    const int WIDTH = 800;
    const int HEIGHT = 600;

    const std::vector<const char*> validationLayers = {
            "VK_LAYER_LUNARG_standard_validation"
    };

    #ifdef NDEBUG
        const bool enableValidationLayers = false;
    #else
        const bool enableValidationLayers = true;//TODO:true
    #endif

    void initWindow();
    void initVulkan();
    void createInstance();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void setupDebugCallback();
    void mainLoop();
    void cleanup();

    GLFWwindow *window;
    VkInstance instance;
    VkDebugReportCallbackEXT callback;

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData) {
        std::cerr << "validation layer: " << msg << std::endl;

        return VK_FALSE;
    }
};


#endif //VULKANVOXEL_HELLOTRIANGLEAPPLICATION_H
