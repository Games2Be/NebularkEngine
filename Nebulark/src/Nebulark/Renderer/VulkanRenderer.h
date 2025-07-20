#pragma once
#include "vulkan/vulkan.h"

namespace Nebulark
{
    class VulkanRenderer
    {
    public:
        void InitVulkan();


    private:
        // Core Vulkan handles
        VkInstance instance = VK_NULL_HANDLE;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice device;
        VkQueue graphicsQueue;
        VkSurfaceKHR surface;

        // Initialization and cleanup
        void createInstance();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void Cleanup();

        // Utility functions
        bool isDeviceSuitable(VkPhysicalDevice device);
        struct QueueFamilyIndices;
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

        // Debugging
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData
        );
    };

}
