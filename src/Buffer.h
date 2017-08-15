//
// Created by philipp on 28.07.17.
//

#ifndef VULKANVOXEL_BUFFER_H
#define VULKANVOXEL_BUFFER_H

#include <iostream>
#include <vulkan/vulkan.h>
#include "Device.h"

class Buffer {
public:
    Buffer();

    virtual Device getDevice() const = 0;
    virtual VkDeviceSize getSize() const = 0;
    virtual VkBufferUsageFlags getUsage() const = 0;
    virtual VkMemoryPropertyFlags getProperties() const = 0;
    virtual VkSharingMode getSharingMode() const = 0;
private:
    VkBuffer vkBuffer;
    VkDeviceMemory vkDeviceMemory;

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
};


#endif //VULKANVOXEL_BUFFER_H
