#pragma once

#include <memory>

#include "Window.h"
#include "events/WindowEvent.h"
#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"

namespace CDE {

	class Application
	{
	public:
		// To be defined by client
		static Application* Create();

		static Application& Get();

		virtual ~Application();

		void Run();
		void OnEvent(Event& event);

		// Takes ownership
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		// Returns ownership
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		Window& GetWindow() { return *m_Window; }

	protected:
		Application();

	private:
		bool HandleWindowClose(const WindowCloseEvent& event);

		static Application* s_Instance;

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
	};

}
