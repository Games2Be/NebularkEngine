#pragma once

#include "Core.h"

namespace Nebulark
{
	class NEBULARK_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//To be defined in CLIENT
	Application* CreateApplication();
}

