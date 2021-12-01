#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Window.h"
#include "Runtime/Events/Event.h"
#include "Runtime/Events/ApplicationEvent.h"

namespace Sudou
{
	class SUDOU_API Application
	{
	public:
		Application();
		~Application();
		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}


