#include "Sudou.h"

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