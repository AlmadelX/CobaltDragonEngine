#include "cdepch.h"
#include "Application.h"

namespace CDE {

	Application::Application()
	{
		std::cout << "Application created!" << std::endl;
	}

	Application::~Application()
	{
		std::cout << "Application destroyed!" << std::endl;
	}

	void Application::Run()
	{
		std::cout << "Running application!" << std::endl;
	}

}
