//
// Created by philipp on 15.08.17.
//

#ifndef VULKANVOXEL_EXTENSIONCONFIGURATION_H
#define VULKANVOXEL_EXTENSIONCONFIGURATION_H

#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <memory>
#include <vulkan/vulkan.h>
#include <map>
#include <algorithm>
#include "Extension.h"
#include "ValidationLayer.h"
#include "PhysicalDevice.h"

class ExtensionConfiguration {
public:
    ExtensionConfiguration();
    ExtensionConfiguration(bool dummy);
    ExtensionConfiguration(std::shared_ptr<ValidationLayer> validationLayer);
    ExtensionConfiguration(std::shared_ptr<ValidationLayer> validationLayer, bool dummy);
    ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice);
    ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,bool dummy);
    ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,std::shared_ptr<ValidationLayer> validationLayer);
    ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,std::shared_ptr<ValidationLayer> validationLayer, bool dummy);

    std::set<std::string> getSupportedExtensionNames();
    std::vector<std::shared_ptr<Extension>> getSupportedExtensions();
    std::map<std::string,std::shared_ptr<Extension>> getExtensionMap();

    bool activateExtension(std::string name);
    bool deactivateExtension(std::string name);
    bool activateExtension(std::shared_ptr<Extension> extension);
    bool deactivateExtension(std::shared_ptr<Extension> extension);
    std::set<std::string> getActivatedExtensions();

    bool isExtensionSupported(std::string name);
    bool isExtensionSupported(std::shared_ptr<Extension> extension);
    
    std::shared_ptr<Extension> getExtension(std::string name);

    std::vector<const char*> extensionData();
private:
    std::map<std::string,std::shared_ptr<Extension>> extensionMap;
    std::set<std::string> activatedExtensions;
};


#endif //VULKANVOXEL_EXTENSIONCONFIGURATION_H
