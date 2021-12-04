#include "Runtime/Core/Application.h"
#include "Runtime/Core/EntryPoint.h"


class ExampleLayer : public Sudou::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		SD_INFO("Example::Update");
	}

	void OnEvent(Sudou::Event& event) override
	{
		SD_TRACE("{0}", event);
	}
};

class Sandbox : public Sudou::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Sudou::Application* Sudou::CreateApplication()
{
	return new Sandbox();
}