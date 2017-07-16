#include <iostream>
#include <stdexcept>
#include <functional>
#include "src/HelloTriangleApplication.h"

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}