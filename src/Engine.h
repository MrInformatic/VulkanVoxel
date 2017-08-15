//
// Created by philipp on 25.07.17.
//

#ifndef VULKANVOXEL_ENGINE_H
#define VULKANVOXEL_ENGINE_H

#include <vulkan/vulkan.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <boost/ptr_container/ptr_array.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "Device.h"
#include "PhysicalDevice.h"
#include "ValidationLayerConfiguration.h"

class Engine {
public:
    Engine();
    Engine(ValidationLayerConfiguration engineConfiguration);

    boost::ptr_vector<PhysicalDevice> getPhysicalDevices();
private:
    VkInstance instance;
};


#endif //VULKANVOXEL_ENGINE_H
