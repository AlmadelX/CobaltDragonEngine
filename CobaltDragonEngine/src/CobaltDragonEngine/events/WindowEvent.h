#pragma once

#include "Event.h"

namespace CDE {

	class WindowEvent : public Event
	{
	public:
		EVENT_CATEGORIES(EventCategoryWindow)
	};

	class WindowCloseEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(WindowClose)
	};

	class WindowFocusEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(WindowFocus)
	};

	class WindowLostFocusEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(WindowLostFocus)
	};

	class WindowMoveEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(WindowMove)

		WindowMoveEvent(int x, int y) : m_X(x), m_Y(y) {}

		virtual std::string ToString() const override;

		inline int GetX() const { return m_X; }
		inline int GetY() const { return m_Y; }

	private:
		const int m_X;
		const int m_Y;
	};

	class WindowResizeEvent : public WindowEvent
	{
	public:
		EVENT_TYPE(WindowResize)

		WindowResizeEvent(int width, int height) : m_Width(width), m_Height(height) {}

		virtual std::string ToString() const override;

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

	private:
		const int m_Width;
		const int m_Height;
	};

}
