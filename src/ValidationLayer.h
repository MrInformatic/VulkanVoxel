//
// Created by philipp on 15.08.17.
//

#ifndef VULKANVOXEL_VALIDATIONLAYER_H
#define VULKANVOXEL_VALIDATIONLAYER_H


#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <vulkan/vulkan.h>
#include <boost/weak_ptr.hpp>
#include "ExtensionConfiguration.h"

class ValidationLayer : ExtensionConfiguration{
public:
    ValidationLayer();
    ValidationLayer(VkLayerProperties vkLayerProperties);
    ValidationLayer(VkLayerProperties vkLayerProperties,bool dummy);
    ValidationLayer(std::shared_ptr<PhysicalDevice> physicalDevice, VkLayerProperties vkLayerProperties);
    ValidationLayer(std::shared_ptr<PhysicalDevice> physicalDevice, VkLayerProperties vkLayerProperties,bool dummy);

    std::string getName();
    std::string getDescription();
    int getSpecVersion();
    int getImplementationVersion();

    std::vector<const char*> extensionData();
private:
    VkLayerProperties vkLayerProperties;
};


#endif //VULKANVOXEL_VALIDATIONLAYER_H
