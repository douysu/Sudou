#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Window.h"
#include "Runtime/Events/Event.h"

namespace Sudou
{
	class SUDOU_API Application
	{
	public:
		Application();
		~Application();
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}


