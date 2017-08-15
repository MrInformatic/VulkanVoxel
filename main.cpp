#include <iostream>
#include <stdexcept>
#include <functional>
#include <memory>
#include "src/HelloTriangleApplication.h"
#include "src/Device.h"
#include "src/ValidationLayer.h"

int main() {
    uint32_t extensionCount;
    vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount,nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount,extensions.data());

    for(auto extension : extensions){
        std::cout << extension.extensionName << std::endl;
    }

    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}