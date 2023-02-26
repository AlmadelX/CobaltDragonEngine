#include "CobaltDragonEngine.h"

class SandboxApp : public CDE::Application
{
public:
	SandboxApp()
	{
		CDE_TRACE("Trace");
		CDE_INFO("Info");
		CDE_WARN("Warn");
		CDE_ERROR("Error");
		CDE_CRITICAL("Critical");
	}

	virtual ~SandboxApp() {}
};

CDE::Application* CreateApplication()
{
	return new SandboxApp;
}
