#pragma once

#include "CobaltDragonEngine/Application.h"

int main(int argc, char** argv)
{
	CDE::Application* app = CDE::CreateApplication();
	app->Run();
	delete app;
}
