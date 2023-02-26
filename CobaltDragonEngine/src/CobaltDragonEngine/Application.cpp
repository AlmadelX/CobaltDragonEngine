#include "cdepch.h"
#include "Application.h"

namespace CDE {

	Application::Application()
	{
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

}
