#pragma once

#include "iostream"
#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

namespace Nebulark
{
	class Window
	{
	public:
		
		Window(const char* name, int width, int height);
		//Create window surface
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		~Window();

	private:
		SDL_Window* window = nullptr;
	};
}
