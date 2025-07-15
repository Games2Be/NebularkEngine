#pragma once

#include "Core.h"
#include "Events/Handlers/EventManager.h"
namespace Nebulark
{
	class NEBULARK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	private:
		bool running = true;
		EventManager eventManager;
	};
	//To be defined in CLIENT
	Application* CreateApplication();
}

