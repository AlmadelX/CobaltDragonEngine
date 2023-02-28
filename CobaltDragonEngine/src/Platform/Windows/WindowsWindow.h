#pragma once

#include <GLFW/glfw3.h>

#include "CobaltDragonEngine/Window.h"

#if defined(CDE_PLATFORM_WINDOWS)
namespace CDE {

	// Single window
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);

		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		inline virtual int GetWidth() const override { return m_Data.Width; }
		virtual int GetHeight() const override { return m_Data.Height; }
		virtual bool IsVSync() const override { return m_Data.VSync; }
		virtual void* GetNativeWindow() const override { return nullptr; }

		virtual void SetVSync(bool vSync) override;
		virtual void SetEventCallback(EventCallback callback) override { m_Data.EventCallback = callback; }

	private:
		struct Data
		{
			std::string Title;
			int Width;
			int Height;
			bool VSync;
			EventCallback EventCallback;
		};

		static void InitGLFW();
		static void ShutdownGLFW();
		static void OnGLFWError(int error, const char* description);

		void SetupGLFWCallbacks();

		static WindowsWindow* s_Instance;

		Data m_Data;
		GLFWwindow* m_Window;
	};

}
#endif
