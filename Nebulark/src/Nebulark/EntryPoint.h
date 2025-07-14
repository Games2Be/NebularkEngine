#pragma once

#ifdef NA_PLATFORM_WINDOWS

extern Nebulark::Application* Nebulark::CreateApplication();

int main(int argc, char** argv)
{
	Nebulark::Log::Init();
	NA_CORE_WARN("Initialized ");
	int a = 5;
	NA_CLIENT_INFO("Hello {0}", a);


	auto app = Nebulark::CreateApplication();
	app->Run();
	delete app;
}
#endif // NA_PLATFORM_WINDOWS
