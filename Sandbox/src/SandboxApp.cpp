#include "Nebulark.h"

class Sandbox : public Nebulark::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{
	}



};

Nebulark::Application* Nebulark::CreateApplication()
{
	return new Sandbox();
}