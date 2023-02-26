#include "CobaltDragonEngine.h"

#include <iostream>

class SandboxApp : public CDE::Application
{
public:
	SandboxApp()
	{
		std::cout << "SandboxApp created!" << std::endl;
	}

	virtual ~SandboxApp()
	{
		std::cout << "SandboxApp deleted!" << std::endl;
	}
};

CDE::Application* CreateApplication()
{
	return new SandboxApp;
}
