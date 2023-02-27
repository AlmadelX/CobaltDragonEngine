#pragma once

#include <memory>

#include "Window.h"
#include "events/WindowEvent.h"

namespace CDE {

	class Application
	{
	public:
		inline static Application& Get() { return *s_Instance; }

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		const Window& GetWindow() const { return *m_Window; }

	private:
		bool OnWindowClose(const WindowCloseEvent& event);

		static Application* s_Instance;

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};

	// To be defined by client
	Application* CreateApplication();

}
