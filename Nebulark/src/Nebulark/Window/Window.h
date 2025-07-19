#pragma once

#include "iostream"
#include "GLFW/glfw3.h"
#include "vulkan/vulkan.h"

namespace Nebulark
{
	class Window
	{
	public:
		
		Window(const char* name, int width, int height);
		~Window();
		GLFWwindow* GetGLFWwindow() const { return window; }

	private:
		GLFWwindow* window;

	};
}
