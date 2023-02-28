#include "CobaltDragonEngine.h"

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}
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
