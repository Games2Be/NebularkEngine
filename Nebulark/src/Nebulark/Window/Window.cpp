#include "Window.h"
#include <stdio.h>
#include <SDL3/SDL.h>
#include "../Log.h"
#include "iostream"


namespace Nebulark
{
	Window::Window(std::string* name, int width, int height)
	{
		

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			const char* error = SDL_GetError();
			NBL_CORE_ERROR("SDL failed to initialise: {0}", error[0] ? error : "(no error message)");

			return;
		}

		window = SDL_CreateWindow((const char*)name, width, height, 0);

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
