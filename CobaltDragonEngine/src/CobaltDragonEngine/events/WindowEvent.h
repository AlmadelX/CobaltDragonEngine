#pragma once

#include "Event.h"

namespace CDE {

	class WindowEvent : public Event {};

	class WindowCloseEvent final : public WindowEvent
	{
	public:
		WindowCloseEvent() = default;
		WindowCloseEvent(const WindowCloseEvent& other) = delete;

		WindowCloseEvent& operator=(const WindowCloseEvent& other) = delete;

		inline virtual std::string GetName() const override { return "WindowCloseEvent"; }
	};

	class WindowFocusEvent final : public WindowEvent
	{
	public:
		WindowFocusEvent() = default;
		WindowFocusEvent(const WindowFocusEvent& other) = delete;

		WindowFocusEvent& operator=(const WindowFocusEvent& other) = delete;

		inline virtual std::string GetName() const override { return "WindowFocusEvent"; }
	};

	class WindowLostFocusEvent final : public WindowEvent
	{
	public:
		WindowLostFocusEvent() = default;
		WindowLostFocusEvent(const WindowLostFocusEvent& other) = delete;

		WindowLostFocusEvent& operator=(const WindowLostFocusEvent& other) = delete;

		inline virtual std::string GetName() const override { return "WindowLostFocusEvent"; }
	};

	class WindowMoveEvent final : public WindowEvent
	{
	public:
		WindowMoveEvent(int x, int y) noexcept : m_X(x), m_Y(y) {}
		WindowMoveEvent(const WindowMoveEvent& other) = delete;

		WindowMoveEvent& operator=(const WindowMoveEvent& other) = delete;

		inline virtual std::string GetName() const override { return "WindowMoveEvent"; }
		virtual std::string ToString() const override;

		inline int GetX() const { return m_X; }
		inline int GetY() const { return m_Y; }

	private:
		const int m_X;
		const int m_Y;
	};

	class WindowResizeEvent final : public WindowEvent
	{
	public:
		WindowResizeEvent(int width, int height) noexcept : m_Width(width), m_Height(height) {}
		WindowResizeEvent(const WindowResizeEvent& other) = delete;

		WindowResizeEvent& operator=(const WindowResizeEvent& other) = delete;

		inline virtual std::string GetName() const override { return "WindowResizeEvent"; }
		virtual std::string ToString() const override;

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

	private:
		const int m_Width;
		const int m_Height;
	};

}
