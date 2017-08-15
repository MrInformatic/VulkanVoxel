//
// Created by philipp on 28.07.17.
//

#ifndef VULKANVOXEL_PHYSICALDEVICE_H
#define VULKANVOXEL_PHYSICALDEVICE_H

#include <vulkan/vulkan.h>

class PhysicalDevice {
public:
    PhysicalDevice();
    PhysicalDevice(VkPhysicalDevice physicalDevice);

    VkPhysicalDevice getPhysicalDevice();
private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};


#endif //VULKANVOXEL_PHYSICALDEVICE_H
