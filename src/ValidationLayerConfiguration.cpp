//
// Created by philipp on 15.08.17.
//

#include "ValidationLayerConfiguration.h"

ValidationLayerConfiguration::ValidationLayerConfiguration() : ValidationLayerConfiguration(false){

}

ValidationLayerConfiguration::ValidationLayerConfiguration(bool dummy) : ExtensionConfiguration(dummy){
    if(!dummy) {
        uint32_t validationLayerCount = 0;
        vkEnumerateInstanceLayerProperties(&validationLayerCount, nullptr);

        std::vector<VkLayerProperties> validationLayers(validationLayerCount);
        vkEnumerateInstanceLayerProperties(&validationLayerCount, validationLayers.data());

        std::transform(validationLayers.begin(), validationLayers.end(), validationLayerMap.begin(),
                       [](VkLayerProperties validationLayer) {
                           return std::pair<std::string, VkLayerProperties>(validationLayer.layerName, validationLayer);
                       });
    }
}

ValidationLayerConfiguration::ValidationLayerConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice):ValidationLayerConfiguration(physicalDevice,
                                                                                                                                        false){

}

ValidationLayerConfiguration::ValidationLayerConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,bool dummy) : ExtensionConfiguration(physicalDevice,dummy){
    if(!dummy) {
        uint32_t validationLayerCount = 0;
        vkEnumerateDeviceLayerProperties(physicalDevice->getPhysicalDevice(),&validationLayerCount, nullptr);

        std::vector<VkLayerProperties> validationLayers(validationLayerCount);
        vkEnumerateDeviceLayerProperties(physicalDevice->getPhysicalDevice(),&validationLayerCount, validationLayers.data());

        std::transform(validationLayers.begin(), validationLayers.end(), validationLayerMap.begin(),
                       [](VkLayerProperties validationLayer) {
                           return std::pair<std::string, VkLayerProperties>(validationLayer.layerName, validationLayer);
                       });
    }
}

std::set<std::string> ValidationLayerConfiguration::getSupportedValidationLayerNames(){
    std::set<std::string> validationLayerNames;
    std::transform(validationLayerMap.begin(),validationLayerMap.end(),validationLayerNames.begin(),
                   [](std::pair<std::string,std::shared_ptr<ValidationLayer>> validationLayer){ return validationLayer.first;});
    return validationLayerNames;
}

std::vector<std::shared_ptr<ValidationLayer>> ValidationLayerConfiguration::getSupportedValidationLayers(){
    std::vector<std::shared_ptr<ValidationLayer>> validationLayers;
    std::transform(validationLayerMap.begin(),validationLayerMap.end(),validationLayers.begin(),
                   [](std::pair<std::string,VkLayerProperties> validationLayer){ return validationLayer.second;});
    return validationLayers;
}

std::map<std::string,std::shared_ptr<ValidationLayer>> ValidationLayerConfiguration::getValidationLayerMap(){
    std::map<std::string,VkLayerProperties> validationLayerMapCopy;
    validationLayerMapCopy.insert(validationLayerMap.begin(),validationLayerMap.end());
}

bool ValidationLayerConfiguration::activateValidationLayer(std::string name){
    if(isValidationLayerSupported(name)){
        throw std::runtime_error("validation layer ("+name+") is not supported");
    }
    return activatedValidationLayers.insert(name).second;
}

bool ValidationLayerConfiguration::deactivateValidationLayer(std::string name){
    return activatedValidationLayers.erase(name)>0;
}

bool ValidationLayerConfiguration::activateValidationLayer(std::shared_ptr<ValidationLayer> validationLayer){
    return activateValidationLayer(validationLayer->getName());
}

bool ValidationLayerConfiguration::deactivateValidationLayer(std::shared_ptr<ValidationLayer> validationLayer){
    return deactivateValidationLayer(validationLayer->getName());
}

std::set<std::string> ValidationLayerConfiguration::getActivatedValidationLayers(){
    return activatedValidationLayers;
}

bool ValidationLayerConfiguration::isValidationLayerSupported(std::string name){
    return validationLayerMap.find(name)!=validationLayerMap.end();
}

bool ValidationLayerConfiguration::isValidationLayerSupported(std::shared_ptr<ValidationLayer> validationLayer){
    return isValidationLayerSupported(validationLayer->getName());
}

std::shared_ptr<ValidationLayer> ValidationLayerConfiguration::getValidationLayer(std::string name){
    return validationLayerMap[name];
}

std::vector<const char*> ValidationLayerConfiguration::validationLayerData(){
    std::vector<const char*> data(activatedValidationLayers.size());
    std::transform(activatedValidationLayers.begin(),activatedValidationLayers.end(),data.begin(),
                   [](std::string name){ return name.data();});
    return data;
}

std::vector<const char*> ValidationLayerConfiguration::finalExtensionData(){
    std::vector<const char*> finalData = extensionData();
    for(std::string validationLayer : activatedValidationLayers){
        std::vector<const char*> data = getValidationLayer(validationLayer)->extensionData();
        finalData.insert(finalData.end(),data.begin(),data.end());
    }
    return finalData;
}