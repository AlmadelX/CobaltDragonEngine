#pragma once

#include <memory>

#include "Window.h"
#include "events/WindowEvent.h"

namespace CDE {

	class Application
	{
	public:
		// To be defined by client
		static Application* Create();

		static Application& Get();

		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		const Window& GetWindow() const { return *m_Window; }

	protected:
		Application();

	private:
		bool OnWindowClose(const WindowCloseEvent& event);

		static Application* s_Instance;

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};

}
