#include "CobaltDragonEngine.h"

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}

	virtual void OnUpdate() override
	{
		CDE_TRACE("Space key polling: {}", CDE::Input::IsKeyPressed(CDE_KEY_SPACE) ? "Pressed" : "Released");
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
