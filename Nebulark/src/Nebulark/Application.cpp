#include "Application.h"
#include "Log.h"
#include "Window/Window.h"
#include "Renderer/VulkanRenderer.h"
namespace Nebulark
{
    Application::Application() 
    {
    }

    Application::~Application() 
    {
    }

	void Application::Run()
	{
        const uint32_t WIDTH = 1280;
        const uint32_t HEIGHT = 680;

		window = new Window("Nebulark Engine", WIDTH, HEIGHT);

		Init();
		Update();
		Shutdown();

		if (window)
		{
			delete window;
			window = nullptr;
		}
	}

    void Application::Init()
    {
		VulkanRenderer renderer;
		renderer.InitVulkan();
    
    }

    void Application::Update()
    {
		if (!window)
		{
			NBL_CORE_ERROR("Window is not initialized.");
			return;
		}

        while (!glfwWindowShouldClose(window->GetGLFWwindow()))
        {
			glfwPollEvents();
        }
    }
    void Application::Shutdown()
    {
		NBL_CORE_INFO("Shutting down Nebulark Engine...");
        NBL_CORE_INFO("Nebulark Engine shutdown complete.");
    }
}
