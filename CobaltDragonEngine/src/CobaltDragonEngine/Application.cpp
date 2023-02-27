#include "cdepch.h"
#include "Application.h"

#include "events/ApplicationEvent.h"
#include "events/EventDispatcher.h"

namespace CDE {

	Application::Application()
	{
		s_Instance = this;
		Log::Init();
		CDE_CORE_INFO("Application created!");
	}

	Application::~Application()
	{
		CDE_CORE_INFO("Application destroyed!");
	}

	void Application::Run()
	{
		CDE_CORE_INFO("Running application!");
	}

	Application* Application::s_Instance;

}
