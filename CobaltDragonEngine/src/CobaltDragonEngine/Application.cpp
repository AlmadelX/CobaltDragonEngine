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
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnRender();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend() && !event.IsHandled(); ++it)
			(*it)->OnEvent(event);
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlayer(overlay);
	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
	}

	void Application::PopOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlayer(overlay);
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
