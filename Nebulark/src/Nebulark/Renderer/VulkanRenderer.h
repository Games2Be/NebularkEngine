#pragma once
#include "vulkan/vulkan.h"

namespace Nebulark
{
    class VulkanRenderer
    {
    public:
        void InitVulkan();

    private:
        VkInstance instance = VK_NULL_HANDLE;
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, 
            VkDebugUtilsMessageTypeFlagsEXT messageType, 
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, 
            void* pUserData);
        struct QueueFamilyIndices;
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        void pickPhysicalDevice();
        bool isDeviceSuitable(VkPhysicalDevice device);
        void createInstance();
        void Cleanup();
    };
}
