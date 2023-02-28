#include "cdepch.h"
#include "Application.h"

#include "events/ApplicationEvent.h"
#include "events/EventDispatcher.h"

namespace CDE {

	Application& Application::Get()
	{
		CDE_ASSERT(s_Instance, "Application is not created yet");
		return *s_Instance;
	}

	Application::~Application()
	{
		CDE_CORE_INFO("Application destroyed");
	}

	void Application::Run()
	{
		CDE_CORE_INFO("Running application");

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_FN(Application::OnWindowClose));
	}

	Application::Application()
		: m_Window(Window::Create())
	{
		CDE_ASSERT(!s_Instance, "Application is already created");
		s_Instance = this;

		Log::Init();
		m_Window->SetEventCallback(BIND_FN(Application::OnEvent));
		CDE_CORE_INFO("Application created");
	}

	bool Application::OnWindowClose(const WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	Application* Application::s_Instance;

}
