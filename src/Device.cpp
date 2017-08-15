//
// Created by philipp on 25.07.17.
//

#include "Device.h"

VkPhysicalDevice Device::getVkPhysicalDevice() {
    return vkPhysicalDevice;
}

VkDevice Device::getVkDevice() {
    return vkDevice;
}
