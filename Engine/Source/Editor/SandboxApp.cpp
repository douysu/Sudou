#include "Runtime/Core/Application.h"
#include "Runtime/Core/EntryPoint.h"
#include "Runtime/GUI/ImGuiLayer.h"
#include "Runtime/Core/Input.h"
#include "Runtime/Core/KeyCodes.h"
#include "Runtime/Core/MouseButtonCodes.h"
#include "imgui/imgui.h"


class ExampleLayer : public Sudou::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		if (Sudou::Input::IsKeyPressed(SD_KEY_TAB))
		{
			SD_TRACE("Tab key is pressed (poll)");
		}
	}

	void OnEvent(Sudou::Event& event) override
	{
		if (event.GetEventType() == Sudou::EventType::KeyPressed)
		{
			Sudou::KeyPressedEvent& e = (Sudou::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SD_KEY_TAB)
				SD_TRACE("Tab key is pressed (event)");
			SD_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello Sudou!");
		ImGui::End();
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