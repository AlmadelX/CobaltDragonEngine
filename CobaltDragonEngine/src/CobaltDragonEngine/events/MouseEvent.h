#pragma once

#include "Event.h"

namespace CDE {

	class MouseEvent : public Event
	{
	public:
		EVENT_CATEGORIES(EventCategoryInput | EventCategoryMouse)
	};

	class MouseMoveEvent : public MouseEvent
	{
	public:
		EVENT_TYPE(MouseMove)

		MouseMoveEvent(float x, float y) : m_X(x), m_Y(y) {}

		virtual std::string ToString() const override;

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

	private:
		const float m_X;
		const float m_Y;
	};

	class MouseScrollEvent : public MouseEvent
	{
	public:
		EVENT_TYPE(MouseScroll)

		MouseScrollEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		virtual std::string ToString() const override;

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

	private:
		const float m_XOffset;
		const float m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		EVENT_CATEGORIES(EventCategoryInput | EventCategoryMouseButton)

		virtual std::string ToString() const override;

		inline int GetButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		const int m_Button;
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		EVENT_TYPE(MouseButtonPress)

		MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		EVENT_TYPE(MouseButtonRelease)

		MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}
	};

}
