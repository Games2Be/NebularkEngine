#pragma once

#ifdef NBL_PLATFORM_WINDOWS

extern Nebulark::Application* Nebulark::CreateApplication();

int main(int argc, char** argv)
{
	Nebulark::Log::Init();
	NBL_CORE_WARN("Starting Engine ");


	auto app = Nebulark::CreateApplication();
	app->Run();
	delete app;
}
#endif // NA_PLATFORM_WINDOWS
