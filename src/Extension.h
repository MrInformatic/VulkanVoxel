//
// Created by philipp on 15.08.17.
//

#ifndef VULKANVOXEL_EXTENSION_H
#define VULKANVOXEL_EXTENSION_H

#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <memory>
#include <vulkan/vulkan.h>
#include <map>
#include <algorithm>

class Extension {
public:
    Extension();
    Extension(VkExtensionProperties vkExtensionProperties);

    std::string getName();
    int getSpecVersion();
private:
    VkExtensionProperties vkExtensionProperties;
};


#endif //VULKANVOXEL_EXTENSION_H
