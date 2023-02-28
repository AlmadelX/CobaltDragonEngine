#include "CobaltDragonEngine.h"

#include <imgui.h>

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}

	virtual void OnImGuiRender() override
	{
		bool show;
		ImGui::ShowDemoWindow(&show);
	}
};

class SandboxApp : public CDE::Application
{
public:
	SandboxApp()
	{
		GameLayer* game = new GameLayer;
		PushLayer(game);
	}
};

CDE::Application* CDE::Application::Create()
{
	return new SandboxApp;
}
