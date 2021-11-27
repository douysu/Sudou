#include "Application.h"
#include "Runtime/stdafx.h"
#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Core/Log.h"

namespace Sudou
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SD_TRACE("EventCategoryApplication");
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SD_TRACE("EventCategoryInput");
		}

		while (true);
	}
}