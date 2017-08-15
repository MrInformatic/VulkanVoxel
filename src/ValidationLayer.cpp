//
// Created by philipp on 15.08.17.
//

#include "ValidationLayer.h"

ValidationLayer::ValidationLayer(){

}

ValidationLayer::ValidationLayer(VkLayerProperties vkLayerProperties) : ValidationLayer(vkLayerProperties,false){

}

ValidationLayer::ValidationLayer(VkLayerProperties vkLayerProperties, bool dummy) : ExtensionConfiguration(std::shared_ptr(this),dummy){
    this->vkLayerProperties = vkLayerProperties;
}

ValidationLayer::ValidationLayer(std::shared_ptr<PhysicalDevice> physicalDevice,
                                 VkLayerProperties vkLayerProperties) : ValidationLayer(physicalDevice,vkLayerProperties,false){

}

ValidationLayer::ValidationLayer(std::shared_ptr<PhysicalDevice> physicalDevice, VkLayerProperties vkLayerProperties,
                                 bool dummy) : ExtensionConfiguration(physicalDevice->getPhysicalDevice(),std::shared_ptr(this),dummy){
    this->vkLayerProperties = vkLayerProperties;


}

std::string ValidationLayer::getName(){
    return VkLayerProperties.layerName;
}

std::string ValidationLayer::getDescription(){
    return vkLayerProperties.description;
}

int ValidationLayer::getSpecVersion(){
    return vkLayerProperties.specVersion;
}

int ValidationLayer::getImplementationVersion(){
    return vkLayerProperties.implementationVersion;
}

std::vector<const char*> ValidationLayer::extensionData(){

}
