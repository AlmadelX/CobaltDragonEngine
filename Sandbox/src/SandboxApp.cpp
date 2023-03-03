#include "CobaltDragonEngine.h"

#include <imgui.h>

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}

	virtual void OnAttach() override
	{
		CDE::RenderCommand::SetClearColor({ 0.1f, 0.8f, 0.7f, 1.0f });
	}

	virtual void OnRender() override
	{
		CDE::RenderCommand::Clear();
	}

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
