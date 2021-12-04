#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Window.h"
#include "Runtime/Events/Event.h"
#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Core/Layer.h"
#include "Runtime/Core/LayerStack.h"

namespace Sudou
{
	class SUDOU_API Application
	{
	public:
		Application();
		~Application();
		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}


