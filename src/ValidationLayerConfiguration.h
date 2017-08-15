//
// Created by philipp on 15.08.17.
//

#ifndef VULKANVOXEL_VALIDATIONLAYERCONFIGURATION_H
#define VULKANVOXEL_VALIDATIONLAYERCONFIGURATION_H

#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <memory>
#include <vulkan/vulkan.h>
#include <map>
#include <algorithm>

#include "PhysicalDevice.h"
#include "ValidationLayer.h"
#include "ExtensionConfiguration.h"

class ValidationLayerConfiguration : ExtensionConfiguration{
public:
    ValidationLayerConfiguration();
    ValidationLayerConfiguration(bool dummy);
    ValidationLayerConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice);
    ValidationLayerConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,bool dummy);

    std::set<std::string> getSupportedValidationLayerNames();
    std::vector<std::shared_ptr<ValidationLayer>> getSupportedValidationLayers();
    std::map<std::string,std::shared_ptr<ValidationLayer>> getValidationLayerMap();

    bool activateValidationLayer(std::string name);
    bool deactivateValidationLayer(std::string name);
    bool activateValidationLayer(std::shared_ptr<ValidationLayer> validationLayer);
    bool deactivateValidationLayer(std::shared_ptr<ValidationLayer> validationLayer);
    std::set<std::string> getActivatedValidationLayers();

    bool isValidationLayerSupported(std::string name);
    bool isValidationLayerSupported(std::shared_ptr<ValidationLayer> validationLayer);

    std::shared_ptr<ValidationLayer> getValidationLayer(std::string name);

    std::vector<const char*> validationLayerData();
    std::vector<const char*> finalExtensionData();
private:
    std::map<std::string,std::shared_ptr<ValidationLayer>> validationLayerMap;
    std::set<std::string> activatedValidationLayers;
};


#endif //VULKANVOXEL_VALIDATIONLAYERCONFIGURATION_H
