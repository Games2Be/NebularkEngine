#pragma once

#include "Core.h"
#include <filesystem>
#include "Log.h"
#include "Window/Window.h"

namespace Nebulark
{
	class NEBULARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void Init();
		void Update();
		void Shutdown();

	private:
		Window* window;

	};
	//To be defined in CLIENT
	Application* CreateApplication();
}

