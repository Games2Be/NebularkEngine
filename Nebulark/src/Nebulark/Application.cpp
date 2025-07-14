#include <SDL3/SDL.h>
#include "Application.h"
#include "Window/Window.h"
#include "iostream"

#define NAME "Nebulark"
#define WIDTH 1280
#define HEIGHT 680

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
		Window window((std::string*)NAME, WIDTH, HEIGHT);

		bool running = true;
		SDL_Event event;

		while (running)
		{
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_EVENT_QUIT) {
					running = false;
				}
			}

			// Placeholder for rendering, updates, etc.
			SDL_Delay(16); // Simulate ~60fps
		}
	}
}
