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

 		void OnAttach() override;
 		void OnDetach() override;
 		void OnImGuiRender() override;

        void Begin();
        void End();
 	private:
 		float m_Time = 0.0f;
 	};

 }