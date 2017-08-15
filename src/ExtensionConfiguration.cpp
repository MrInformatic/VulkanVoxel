//
// Created by philipp on 15.08.17.
//

#include "ExtensionConfiguration.h"

ExtensionConfiguration::ExtensionConfiguration() : ExtensionConfiguration(false){

}

ExtensionConfiguration::ExtensionConfiguration(bool dummy){
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensionProperties(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensionProperties.data());

    std::transform(extensionProperties.begin(),extensionProperties.end(),activatedExtensions.begin(),
                   [](VkExtensionProperties extensionPropertie){
                       return extensionPropertie.extensionName;
                   });

    if(!dummy){
        std::transform(extensionProperties.begin(),extensionProperties.end(),extensionMap.begin(),
                       [](VkExtensionProperties extensionPropertie){
                           auto extension = std::make_shared<Extension>(extensionPropertie);
                           return std::pair<std::string,std::shared_ptr<Extension>>(extension->getName(),extension);
                       });
    }
}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<ValidationLayer> validationLayer) : ExtensionConfiguration(validationLayer,false){

}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<ValidationLayer> validationLayer, bool dummy){
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(validationLayer->getName().data(), &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensionProperties(extensionCount);
    vkEnumerateInstanceExtensionProperties(validationLayer->getName().data(), &extensionCount, extensionProperties.data());

    std::transform(extensionProperties.begin(),extensionProperties.end(),activatedExtensions.begin(),
                   [](VkExtensionProperties extensionPropertie){
                       return extensionPropertie.extensionName;
                   });

    if(!dummy){
        std::transform(extensionProperties.begin(),extensionProperties.end(),extensionMap.begin(),
                       [](VkExtensionProperties extensionPropertie){
                           auto extension = std::make_shared<Extension>(extensionPropertie);
                           return std::pair<std::string,std::shared_ptr<Extension>>(extension->getName(),extension);
                       });
    }
}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice) : ExtensionConfiguration(physicalDevice,false){

}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,bool dummy){
    uint32_t extensionCount = 0;
    vkEnumerateDeviceExtensionProperties(physicalDevice->getPhysicalDevice(), nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensionProperties(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice->getPhysicalDevice(), nullptr, &extensionCount, extensionProperties.data());

    std::transform(extensionProperties.begin(),extensionProperties.end(),activatedExtensions.begin(),
                   [](VkExtensionProperties extensionPropertie){
                       return extensionPropertie.extensionName;
                   });

    if(!dummy){
        std::transform(extensionProperties.begin(),extensionProperties.end(),extensionMap.begin(),
                       [](VkExtensionProperties extensionPropertie){
                           auto extension = std::make_shared<Extension>(extensionPropertie);
                           return std::pair<std::string,std::shared_ptr<Extension>>(extension->getName(),extension);
                       });
    }
}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,std::shared_ptr<ValidationLayer> validationLayer) : ExtensionConfiguration(physicalDevice,validationLayer){

}

ExtensionConfiguration::ExtensionConfiguration(std::shared_ptr<PhysicalDevice> physicalDevice,std::shared_ptr<ValidationLayer> validationLayer, bool dummy){
    uint32_t extensionCount = 0;
    vkEnumerateDeviceExtensionProperties(physicalDevice->getPhysicalDevice(), validationLayer->getName().data(), &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensionProperties(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice->getPhysicalDevice(), validationLayer->getName().data(), &extensionCount, extensionProperties.data());

    std::transform(extensionProperties.begin(),extensionProperties.end(),activatedExtensions.begin(),
                   [](VkExtensionProperties extensionPropertie){
                       return extensionPropertie.extensionName;
                   });

    if(!dummy){
        std::transform(extensionProperties.begin(),extensionProperties.end(),extensionMap.begin(),
                       [](VkExtensionProperties extensionPropertie){
                           auto extension = std::make_shared<Extension>(extensionPropertie);
                           return std::pair<std::string,std::shared_ptr<Extension>>(extension->getName(),extension);
                       });
    }
}

std::set<std::string> ExtensionConfiguration::getSupportedExtensionNames(){
    std::set<std::string> extensionNames;
    std::transform(extensionMap.begin(),extensionMap.end(),extensionNames.begin(),
                   [](std::pair<std::string,std::shared_ptr<Extension>> extensionPair){
                       return extensionPair.first;
                   });
}

std::vector<std::shared_ptr<Extension>> ExtensionConfiguration::getSupportedExtensions(){
    std::vector<std::shared_ptr<Extension>> extensions(extensionMap.size());
    std::transform(extensionMap.begin(),extensionMap.end(),extensions.begin(),
                   [](std::pair<std::string,std::shared_ptr<Extension>> extensionPair){
                       return extensionPair.second;
                   });
}

std::map<std::string,std::shared_ptr<Extension>> ExtensionConfiguration::getExtensionMap(){
    std::map<std::string,std::shared_ptr<Extension>> extensionMapCopy;
    extensionMapCopy.insert(extensionMap.begin(),extensionMap.end());
    return extensionMapCopy;
}

bool ExtensionConfiguration::activateExtension(std::string name){
    if(!isExtensionSupported(name)){
        throw std::runtime_error("extension ("+name+") is not supported");
    }
    return activatedExtensions.insert(name).second;
}

bool ExtensionConfiguration::deactivateExtension(std::string name){
    return activatedExtensions.erase(name)>0;
}

bool ExtensionConfiguration::activateExtension(std::shared_ptr<Extension> extension){
    return activateExtension(extension->getName());
}

bool ExtensionConfiguration::deactivateExtension(std::shared_ptr<Extension> extension){
    return deactivateExtension(extension->getName());
}

std::set<std::string> ExtensionConfiguration::getActivatedExtensions(){
    return activatedExtensions;
}

bool ExtensionConfiguration::isExtensionSupported(std::string name){
    return extensionMap.find(name)!=extensionMap.end();
}

bool ExtensionConfiguration::isExtensionSupported(std::shared_ptr<Extension> extension){
    return isExtensionSupported(extension->getName());
}

std::shared_ptr<Extension> ExtensionConfiguration::getExtension(std::string name){
    return extensionMap[name];
}

std::vector<const char*> ExtensionConfiguration::extensionData(){
    std::vector<const char*> data(activatedExtensions.size());
    std::transform(activatedExtensions.begin(),activatedExtensions.end(),data.begin(),
                   [](std::string name){ return name.data();});
    return data;
}
