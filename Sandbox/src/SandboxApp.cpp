#include "CobaltDragonEngine.h"

class SandboxApp : public CDE::Application
{
public:
	SandboxApp()
	{
		
	}

	virtual ~SandboxApp()
	{

	}
};

CDE::Application* CDE::Application::Create()
{
	return new SandboxApp;
}
