cmake_minimum_required(VERSION 3.7)
project(VulkanVoxel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/HelloTriangleApplication.cpp src/HelloTriangleApplication.h)
link_directories(/home/philipp/Programme/VulkanSDK/1.0.54.0/x86_64/lib/)
add_executable(VulkanVoxel ${SOURCE_FILES})
target_link_libraries(VulkanVoxel vulkan glfw3 X11 Xxf86vm Xrandr pthread Xi Xcursor Xinerama dl)


