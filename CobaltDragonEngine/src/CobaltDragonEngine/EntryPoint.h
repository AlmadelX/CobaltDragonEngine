#pragma once

#include "CobaltDragonEngine/Application.h"

int main(int argc, char** argv)
{
	CDE::Application* app = CDE::Application::Create();
	app->Run();
	delete app;
}
