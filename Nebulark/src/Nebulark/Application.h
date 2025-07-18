#pragma once

#include "Core.h"
#include "Events/Handlers/EventManager.h"
#include "Graphics/RenderPipeline.h"
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

	private:

		bool running = true;
		EventManager eventManager;

		RenderPipeline pipeline{
			"Shaders/simple_shader_vert.spv",
			"Shaders/simple_shader_frag.spv"
		};


	};
	//To be defined in CLIENT
	Application* CreateApplication();
}

