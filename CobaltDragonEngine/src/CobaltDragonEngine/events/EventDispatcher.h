#pragma once

#include <functional>

#include "Event.h"

namespace CDE {

	class EventDispatcher
	{
		template<typename T>
		using HandleEvent = std::function<bool(const T&)>;

	public:
		EventDispatcher(Event& event) noexcept : m_Event(event) {}
		EventDispatcher(const EventDispatcher& other) = delete;

		EventDispatcher& operator=(const EventDispatcher& other) = delete;

		template<typename T>
		void Dispatch(HandleEvent<T> handle) const
		{
			if (m_Event.m_Handled)
				return;

			const T* event = dynamic_cast<const T*>(&m_Event);
			if (event)
				m_Event.m_Handled = handle(*event);
		}

	private:
		Event& m_Event;
	};

}
