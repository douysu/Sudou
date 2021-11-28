#pragma once

#include "Runtime/Core/Core.h"

namespace Sudou
{
	class SUDOU_API Application
	{
	public:
		Application();
		~Application();
		void Run();
	};

	Application* CreateApplication();
}


