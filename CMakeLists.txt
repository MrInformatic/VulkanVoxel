cmake_minimum_required(VERSION 3.7)
project(VulkanVoxel)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/HelloTriangleApplication.cpp src/HelloTriangleApplication.h src/Engine.cpp src/Engine.h src/Device.cpp src/Device.h src/Buffer.cpp src/Buffer.h src/PhysicalDevice.cpp src/PhysicalDevice.h src/ValidationLayer.cpp src/ValidationLayer.h src/ValidationLayerConfiguration.cpp src/ValidationLayerConfiguration.h src/ExtensionConfiguration.cpp src/ExtensionConfiguration.h src/Extension.cpp src/Extension.h)
link_directories(/home/philipp/Programme/VulkanSDK/1.0.54.0/x86_64/lib/)
add_executable(VulkanVoxel ${SOURCE_FILES})
target_link_libraries(VulkanVoxel vulkan glfw3 X11 Xxf86vm Xrandr pthread Xi Xcursor Xinerama boost_system pthread dl)


