#include "cdepch.h"
#include "WindowsWindow.h"

#include "CobaltDragonEngine/events/WindowEvent.h"

#define CALLBACK(callback) Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));\
						   callback\
						   data.EventCallback(event)

namespace CDE {

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
		: m_Data{ props.Title, props.Width, props.Height }
	{
		InitGLFW();

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		glfwMakeContextCurrent(m_Window);
		SetVSync(true);

		SetupGLFWCallbacks();
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_Window);
		ShutdownGLFW();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool vSync)
	{
		m_Data.VSync = vSync;

		if (vSync)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void WindowsWindow::InitGLFW()
	{
		glfwSetErrorCallback(OnGLFWError);
		CDE_CORE_ASSERT(glfwInit(), "Failed to initalize GLFW");
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	}

	void WindowsWindow::OnGLFWError(int error, const char* description)
	{
		CDE_CORE_ERROR("GLFW Error {}: {}", error, description);
	}

	void WindowsWindow::ShutdownGLFW()
	{
		glfwTerminate();
	}

	void WindowsWindow::SetupGLFWCallbacks()
	{
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			CALLBACK(
				WindowCloseEvent event;
			);
		});
	}

}
