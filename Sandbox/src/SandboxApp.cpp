#include "CobaltDragonEngine.h"

class SandboxApp : public CDE::Application
{
public:
	SandboxApp()
	{
		
	}

	virtual ~SandboxApp() {}
};

CDE::Application* CDE::CreateApplication()
{
	return new SandboxApp;
}
