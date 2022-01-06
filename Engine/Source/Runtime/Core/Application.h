#pragma once

#include "Runtime/Core/Core.h"
#include "Runtime/Core/Window.h"
#include "Runtime/Events/Event.h"
#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Core/Layer.h"
#include "Runtime/Core/LayerStack.h"
#include "Runtime/GUI/ImGuiLayer.h"
#include "Runtime/Renderer/Shader.h"
#include "Runtime/Renderer/Buffer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


