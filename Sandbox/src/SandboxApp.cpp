#include "CobaltDragonEngine.h"

#include <glm/vec3.hpp>

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game")
	{
		glm::vec3 v(1.0f, 2.0f, 3.0f);
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
