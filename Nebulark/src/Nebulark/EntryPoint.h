#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>

#ifdef NBL_PLATFORM_WINDOWS

extern Nebulark::Application* Nebulark::CreateApplication();

int main(int argc, char** argv)
{
	Nebulark::Log::Init();

	NBL_CORE_INFO("Current working directory: {0}", std::filesystem::current_path().string());
	NBL_CORE_WARN("Starting Engine ");


	auto app = Nebulark::CreateApplication();
	app->Run();
	delete app;
}
#endif // NA_PLATFORM_WINDOWS
