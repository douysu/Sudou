#include "Runtime/Application.h"
#include "Runtime/EntryPoint.h"

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