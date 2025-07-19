#include "Window.h"
#include "../Log.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "vulkan/vulkan.h"

namespace Nebulark
{

    Window::Window(const char* name, int width, int height)
    {
        if (!glfwInit())
        {
            NBL_CORE_ERROR("Failed to initialize GLFW");
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, name, nullptr, nullptr);
        if (!window)
        {
            NBL_CORE_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

    }


    Window::~Window()
    {
		if (window)
		{
			glfwDestroyWindow(window);
			window = nullptr;
		}
		glfwTerminate();
    }
}

