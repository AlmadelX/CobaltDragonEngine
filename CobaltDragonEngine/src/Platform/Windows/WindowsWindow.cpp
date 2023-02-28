#include "cdepch.h"
#include "WindowsWindow.h"

#include "CobaltDragonEngine/events/WindowEvent.h"
#include "CobaltDragonEngine/events/KeyEvent.h"
#include "CobaltDragonEngine/events/MouseEvent.h"

namespace CDE {

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
		: m_Data{ props.Title, props.Width, props.Height }
	{
		CDE_ASSERT(!s_Instance, "Only one window is supported");
		s_Instance = this;

		InitGLFW();

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetupGLFWCallbacks();

		glfwMakeContextCurrent(m_Window);
		SetVSync(true);

		// Temporary
		CDE_CORE_ASSERT(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)), "Failed to initialize glad");
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

	void WindowsWindow::ShutdownGLFW()
	{
		glfwTerminate();
	}

	void WindowsWindow::OnGLFWError(int error, const char* description)
	{
		CDE_CORE_ERROR("GLFW Error {}: {}", error, description);
	}

	void WindowsWindow::SetupGLFWCallbacks()
	{
		// Window callbacks
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			if (focused)
			{
				WindowFocusEvent event;
				data.EventCallback(event);
			}
			else
			{
				WindowLostFocusEvent event;
				data.EventCallback(event);
			}
		});

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int x, int y)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			WindowMoveEvent event(x, y);
			data.EventCallback(event);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		// Keyboard callbacks
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressEvent event(key, false);
				data.EventCallback(event);
				return;
			}

			case GLFW_REPEAT:
			{
				KeyPressEvent event(key, true);
				data.EventCallback(event);
				return;
			}

			case GLFW_RELEASE:
			{
				KeyReleaseEvent event(key);
				data.EventCallback(event);
				return;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			KeyTypeEvent event(codepoint);
			data.EventCallback(event);
		});

		// Mouse callbacks
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			MouseMoveEvent event(static_cast<float>(xpos), static_cast<float>(ypos));
			data.EventCallback(event);
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			MouseScrollEvent event(static_cast<float>(xoffset), static_cast<float>(yoffset));
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			Data& data = *reinterpret_cast<Data*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressEvent event(button);
				data.EventCallback(event);
				return;
			}

			case GLFW_RELEASE:
			{
				MouseButtonReleaseEvent event(button);
				data.EventCallback(event);
				return;
			}
			}
		});
	}

	WindowsWindow* WindowsWindow::s_Instance;

}
