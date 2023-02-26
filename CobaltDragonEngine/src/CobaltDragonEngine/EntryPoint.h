#pragma once

#include "CobaltDragonEngine/Application.h"

extern CDE::Application* CreateApplication();

int main(int argc, char** argv)
{
	CDE::Application* app = CreateApplication();
	app->Run();
	delete app;
}
