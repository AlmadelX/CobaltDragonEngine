#pragma once

#include "Event.h"

namespace CDE {

	class InputEvent : public Event {};

	// Key events

	class KeyEvent : public InputEvent
	{
	public:
		virtual std::string ToString() const override;
		inline int GetKey() const { return m_Key; }

	protected:
		KeyEvent(int key) noexcept : m_Key(key) {}

		const int m_Key;
	};

	class KeyPressEvent final : public KeyEvent
	{
	public:
		KeyPressEvent(int key, bool repeat) noexcept : KeyEvent(key), m_Repeat(repeat) {}
		KeyPressEvent(const KeyPressEvent& other) = delete;

		KeyPressEvent& operator=(const KeyPressEvent& other) = delete;

		inline virtual std::string GetName() const override { return "KeyPressEvent"; }
		virtual std::string ToString() const override;

		inline bool IsRepeat() const { return m_Repeat; }

	private:
		const bool m_Repeat;
	};

	class KeyReleaseEvent final : public KeyEvent
	{
	public:
		KeyReleaseEvent(int key) noexcept : KeyEvent(key) {}
		KeyReleaseEvent(const KeyReleaseEvent& other) = delete;

		KeyReleaseEvent& operator=(const KeyReleaseEvent& other) = delete;

		inline virtual std::string GetName() const override { return "KeyReleaseEvent"; }
	};

	class KeyTypeEvent final : public KeyEvent
	{
	public:
		KeyTypeEvent(int key) noexcept : KeyEvent(key) {}
		KeyTypeEvent(const KeyTypeEvent& other) = delete;

		KeyTypeEvent& operator=(const KeyTypeEvent& other) = delete;

		inline virtual std::string GetName() const override { return "KeyTypeEvent"; }
	};

	// Mouse events

	class MouseEvent : public InputEvent {};

	class MouseMoveEvent final : public MouseEvent
	{
	public:
		MouseMoveEvent(float x, float y) noexcept : m_X(x), m_Y(y) {}
		MouseMoveEvent(const MouseMoveEvent& other) = delete;

		MouseMoveEvent& operator=(const MouseMoveEvent& other) = delete;

		inline virtual std::string GetName() const override { return "MouseMoveEvent"; }
		virtual std::string ToString() const override;

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }

	private:
		const float m_X;
		const float m_Y;
	};

	class MouseScrollEvent final : public MouseEvent
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset) noexcept : m_XOffset(xOffset), m_YOffset(yOffset) {}
		MouseScrollEvent(const MouseScrollEvent& other) = delete;

		MouseScrollEvent& operator=(const MouseScrollEvent& other) = delete;

		inline virtual std::string GetName() const override { return "MouseScrollEvent"; }
		virtual std::string ToString() const override;

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

	private:
		const float m_XOffset;
		const float m_YOffset;
	};

	class MouseButtonEvent : public MouseEvent
	{
	public:
		virtual std::string ToString() const override;
		inline int GetButton() const { return m_Button; }

	protected:
		MouseButtonEvent(int button) noexcept : m_Button(button) {}

		const int m_Button;
	};

	class MouseButtonPressEvent final : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int button) noexcept : MouseButtonEvent(button) {}
		MouseButtonPressEvent(const MouseButtonPressEvent& other) = delete;

		MouseButtonPressEvent& operator=(const MouseButtonPressEvent& other) = delete;

		inline virtual std::string GetName() const override { return "MouseButtonPressEvent"; }
	};

	class MouseButtonReleaseEvent final : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int button) noexcept : MouseButtonEvent(button) {}
		MouseButtonReleaseEvent(const MouseButtonReleaseEvent& other) = delete;

		MouseButtonReleaseEvent& operator=(const MouseButtonReleaseEvent& other) = delete;

		inline virtual std::string GetName() const override { return "MouseButtonReleaseEvent"; }
	};

}
