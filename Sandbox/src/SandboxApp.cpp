#include "CobaltDragonEngine.h"

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}

	virtual ~GameLayer() = default;

	virtual void OnAttach()
	{
		CDE_TRACE("Game attached");
	}

	virtual void OnDetach()
	{
		CDE_TRACE("Game detached");
	}

	virtual void OnUpdate()
	{
		CDE_TRACE("Game updated");
	}

	virtual void OnRender()
	{
		CDE_TRACE("Game rendered");
	}

	virtual void OnEvent(CDE::Event& event)
	{
		CDE_TRACE("Game event: {}", event);
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
