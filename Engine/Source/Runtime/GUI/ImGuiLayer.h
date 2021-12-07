#pragma once

#include "Runtime/Core/Layer.h"
#include "Runtime/Events/ApplicationEvent.h"
#include "Runtime/Events/KeyEvent.h"
#include "Runtime/Events/MouseEvent.h"

 namespace Sudou {

 	class SUDOU_API ImGuiLayer : public Layer
 	{
 	public:
 		ImGuiLayer();
 		~ImGuiLayer();

 		void OnAttach();
 		void OnDetach();
 		void OnUpdate();
 		void OnEvent(Event& event);
 	private:
 		float m_Time = 0.0f;
    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);
 	};

 }