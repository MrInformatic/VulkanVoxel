//
// Created by philipp on 25.07.17.
//

#include "Engine.h"


Engine::Engine() : Engine(ValidationLayerConfiguration(true)){

}

Engine::Engine(ValidationLayerConfiguration engineConfiguration) {
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = engineConfiguration.finalExtensionData();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    auto validationLayerData = engineConfiguration.validationLayerData();

    if (validationLayerData.size()>0) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayerData.size());
        createInfo.ppEnabledLayerNames = validationLayerData.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}

/*std::vector<VkExtensionProperties> Engine::getExtensions() {
    uint32_t extensionCount;
    vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount,nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount,extensions.data());

    return extensions;
}

std::set<std::string> Engine::getExtensionNames() {
    auto extensions = getExtensions();
    std::set<const char*> extensionNames;

    std::transform(extensions.begin(),extensions.end(),extensionNames.begin(),[](VkExtensionProperties extension) {return extension.extensionName;});

    return extensionNames;
}*/

boost::ptr_vector<PhysicalDevice> Engine::getPhysicalDevices(){
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    std::vector<VkPhysicalDevice> vkPhysicalDevices;
    vkEnumeratePhysicalDevices(instance, &deviceCount, vkPhysicalDevices.data());

    boost::ptr_vector<PhysicalDevice> physikalDevices;
    std::transform(vkPhysicalDevices.begin(),vkPhysicalDevices.end(),physikalDevices.begin(),[](VkPhysicalDevice vkPhysicalDevice) {return std::make_unique(vkPhysicalDevices);});

    return physikalDevices;
}

