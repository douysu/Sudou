#include "Runtime/Core/Application.h"
#include "Runtime/Core/EntryPoint.h"

class Sandbox : public Sudou::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Sudou::Application* Sudou::CreateApplication()
{
	return new Sandbox();
}