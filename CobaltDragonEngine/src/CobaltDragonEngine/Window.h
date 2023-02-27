#pragma once

#include <string>
#include <functional>

#include "events/Event.h"

namespace CDE {

	struct WindowProps
	{
		std::string Title = "Cobalt Dragon Engine";
		int Width = 1280;
		int Height = 720;
	};

	// Desktop window
	class Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		// To be defined by platform window implementation
		static Window* Create(const WindowProps& props = {});

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual bool IsVSync() const = 0;
		virtual void* GetNativeWindow() const = 0;

		virtual void SetVSync(bool vSync) = 0;
		virtual void SetEventCallback(EventCallback callback) = 0;
	};

}
