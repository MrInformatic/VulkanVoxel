//
// Created by philipp on 15.08.17.
//

#include "Extension.h"

Extension::Extension() {

}

Extension::Extension(VkExtensionProperties vkExtensionProperties) {
    this->vkExtensionProperties = vkExtensionProperties;
}

std::string Extension::getName() {
    return vkExtensionProperties.extensionName;
}

int Extension::getSpecVersion() {
    return vkExtensionProperties.specVersion;
}