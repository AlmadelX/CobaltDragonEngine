#pragma once

#include "Event.h"

namespace CDE {

	class KeyEvent : public Event
	{
	public:
		EVENT_CATEGORIES(EventCategoryInput | EventCategoryKeyboard)

		virtual std::string ToString() const override;

		inline int GetKey() const { return m_Key; }

	protected:
		KeyEvent(int key) : m_Key(key) {}

		const int m_Key;
	};

	class KeyPressEvent : public KeyEvent
	{
	public:
		EVENT_TYPE(KeyPress)

		KeyPressEvent(int key, bool repeat) : KeyEvent(key), m_Repeat(repeat) {}

		virtual std::string ToString() const override;

		inline bool IsRepeat() const { return m_Repeat; }

	private:
		const bool m_Repeat;
	};

	class KeyReleaseEvent : public KeyEvent
	{
	public:
		EVENT_TYPE(KeyRelease)

		KeyReleaseEvent(int key) : KeyEvent(key) {}
	};

	class KeyTypeEvent : public KeyEvent
	{
	public:
		EVENT_TYPE(KeyType)

		KeyTypeEvent(int key) : KeyEvent(key) {}
	};

}
