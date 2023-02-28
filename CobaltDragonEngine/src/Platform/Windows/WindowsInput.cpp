#include "cdepch.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>

#include "CobaltDragonEngine/Application.h"

namespace CDE {

	Input* Input::s_Instance = new WindowsInput;

	WindowsInput::WindowsInput()
	{
		CDE_CORE_ASSERT(!Input::IsInstanceSet(), "Only one input instance is allowed");
	}

	bool WindowsInput::IsKeyPressedImpl(int keyCode) const
	{
		GLFWwindow* window = reinterpret_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl() const
	{
		GLFWwindow* window = reinterpret_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { static_cast<float>(x), static_cast<float>(y) };
	}

	float WindowsInput::GetMouseXImpl() const
	{
		auto [x, y] = GetMousePosImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl() const
	{
		auto [x, y] = GetMousePosImpl();
		return y;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) const
	{
		GLFWwindow* window = reinterpret_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

}
