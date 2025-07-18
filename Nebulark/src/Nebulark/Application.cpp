#include <SDL3/SDL.h>
#include "Application.h"
#include "Window/Window.h"
#include "iostream"
#include "Events/Handlers/EventManager.h"#include "Events/Event.h"
#include "SDL3/SDL_keycode.h"
#include "Log.h"
#include "Events/Types/KeyEvent.h"
#include "Events/Types/MouseEvent.h"
#include "Events/InputManager.h"
#include "Core/Timer.h"
#include <filesystem>

#define WIDTH 1280
#define HEIGHT 680

namespace Nebulark
{
	Application::Application() {
		eventManager.RegisterListener(EventType::Quit, [this](Event& e) {
			NBL_CORE_INFO("Quit event received, shutting down application.");
			// Handle cleanup or shutdown logic here if needed
			running = false;
			});
	}

	Application::~Application() {}

	void Application::Run()
	{

		const char *windowName = "Nebulark";

		// Initializers go here
		Window window(windowName, WIDTH, HEIGHT);
		InputManager Input(eventManager);
		Timer timer;

		running = true;

		while (running)
		{

			float deltaTime = timer.getDeltaTime();


			Input.Reset(); 
			eventManager.PollEvents();
			if (Input.IsMouseButtonJustPressed(1)){
				NBL_CORE_INFO("Mouse pos x: {0}, Mouse pos y: {1}", Input.GetMouseX(), Input.GetMouseY());
			}

			if (Input.IsKeyJustPressed(SDLK_ESCAPE)) {
				NBL_CORE_INFO("Escape key pressed");
			}

			if (Input.IsKeyJustReleased(SDLK_SPACE)) {
				NBL_CORE_INFO("Mouse pos x: {0}, Mouse pos y: {1}", Input.GetMouseX(), Input.GetMouseY());
			}

			if (Input.IsStickJustPressed(SDL_GAMEPAD_BUTTON_DPAD_UP))
			{
				NBL_CORE_INFO("Gamepad North button pressed.");
			}

			// Render logic would go here

			

			SDL_Delay(16);
		}
	}
}

