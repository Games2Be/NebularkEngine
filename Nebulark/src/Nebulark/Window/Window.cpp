#include "Window.h"
#include <stdio.h>
#include <SDL3/SDL.h>
#include "../Log.h"
#include "iostream"
#include <SDL3/SDL_vulkan.h>


namespace Nebulark
{
	Window::Window(const char *name, int width, int height)
	{
		

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD) < 0) {
			const char* error = SDL_GetError();
			NBL_CORE_ERROR("SDL failed to initialise: {0}", error[0] ? error : "(no error message)");

			return;
		}

		window = SDL_CreateWindow(name, width, height, SDL_WINDOW_VULKAN);

		if (window == nullptr) {
			const char* error = SDL_GetError();
			NBL_CORE_ERROR("SDL window failed to initialise: {0}", error[0] ? error : "(no error message)");
			SDL_Quit();
			return;
		}
		else
		{
			NBL_CORE_INFO("SDL window created successfully");
		}
	}


	void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (!SDL_Vulkan_CreateSurface(window, instance, nullptr, surface)) {
			const char* error = SDL_GetError();
			NBL_CORE_ERROR("Failed to create Vulkan surface: {0}", error[0] ? error : "(no error message)");
			return;
		}
		else
		{
			NBL_CORE_INFO("Vulkan surface created successfully");
		}
	}

	Window::~Window()
	{
		if (window)
		{
			NBL_CORE_INFO("Destroying SDL window");
			SDL_DestroyWindow(window);
			window = nullptr;
		}
		SDL_Quit();
	}
}
