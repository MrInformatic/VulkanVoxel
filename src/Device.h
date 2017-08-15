//
// Created by philipp on 25.07.17.
//

#ifndef VULKANVOXEL_DEVICE_H
#define VULKANVOXEL_DEVICE_H


#include <vulkan/vulkan.h>
#include <iostream>

class Device {
public:
    VkPhysicalDevice getVkPhysicalDevice();
    VkDevice getVkDevice();
private:
    VkPhysicalDevice vkPhysicalDevice = VK_NULL_HANDLE;
    VkDevice vkDevice;
};


#endif //VULKANVOXEL_DEVICE_H
