#pragma once

#include "iostream"
#include <SDL3/SDL.h>

namespace Nebulark
{
	class Window
	{
	public:
		Window(const char *name, int width, int height);
		~Window();

	private:
		SDL_Window* window = nullptr;
	};
}
