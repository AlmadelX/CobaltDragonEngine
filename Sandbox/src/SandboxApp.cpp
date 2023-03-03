#include "CobaltDragonEngine.h"

class GameLayer : public CDE::Layer
{
public:
	GameLayer() : Layer("Game") {}

	virtual void OnAttach() override
	{
		CDE::RenderCommand::SetClearColor({ 0.1f, 0.8f, 0.7f, 1.0f });

		// Test events
		CDE::AppTickEvent appTick(1.0f / 60.0f);
		CDE::AppUpdateEvent appUpdate;
		CDE::AppRenderEvent appRender;

		CDE::WindowCloseEvent windowClose;
		CDE::WindowFocusEvent windowFocus;
		CDE::WindowLostFocusEvent windowLostFocus;
		CDE::WindowMoveEvent windowMove(1280, 720);
		CDE::WindowResizeEvent windowResize(1920, 1080);

		CDE::KeyPressEvent keyPress(65, true);
		CDE::KeyReleaseEvent keyRelease(66);
		CDE::KeyTypeEvent keyType(67);

		CDE::MouseMoveEvent mouseMove(100.0f, 200.0f);
		CDE::MouseScrollEvent mouseScroll(5.0f, -2.0f);
		CDE::MouseButtonPressEvent mouseButtonPress(0);
		CDE::MouseButtonReleaseEvent mouseButtonRelease(1);

		CDE_TRACE("{}", appTick);
		CDE_TRACE("{}", appUpdate);
		CDE_TRACE("{}", appRender);
		CDE_TRACE("");

		CDE_TRACE("{}", windowClose);
		CDE_TRACE("{}", windowFocus);
		CDE_TRACE("{}", windowLostFocus);
		CDE_TRACE("{}", windowMove);
		CDE_TRACE("{}", windowResize);
		CDE_TRACE("");

		CDE_TRACE("{}", keyPress);
		CDE_TRACE("{}", keyRelease);
		CDE_TRACE("{}", keyType);
		CDE_TRACE("");

		CDE_TRACE("{}", mouseMove);
		CDE_TRACE("{}", mouseScroll);
		CDE_TRACE("{}", mouseButtonPress);
		CDE_TRACE("{}", mouseButtonRelease);
		CDE_TRACE("");

		CDE::EventDispatcher dispatcher(windowClose);
		dispatcher.Dispatch<CDE::KeyPressEvent>([](const CDE::KeyPressEvent& e) {
			CDE_TRACE("Key press: {}", e);
			return true;
		});
		dispatcher.Dispatch<CDE::WindowCloseEvent>([](const CDE::WindowCloseEvent& e) {
			CDE_TRACE("Window close: {}", e);
			return true;
		});

		if (std::is_base_of<CDE::MouseEvent, decltype(keyPress)>())
		{
			CDE_TRACE("Mouse event");
		}
		else if (std::is_base_of < CDE::InputEvent, decltype(keyPress)>())
		{
			CDE_TRACE("Input event");
		}
	}

	virtual void OnRender() override
	{
		CDE::RenderCommand::Clear();
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
