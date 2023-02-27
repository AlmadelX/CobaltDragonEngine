#pragma once

#include <functional>

#include "Event.h"

namespace CDE {

	class EventDispatcher
	{
		template<typename T>
		using EventHandler = std::function<bool(const T&)>;

	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		void Dispatch(EventHandler<T> handler) const
		{
			if (!m_Event.IsHandled() && m_Event.GetType() == T::Type())
				m_Event.m_Handled = handler(dynamic_cast<const T&>(m_Event));
		}

	private:
		Event& m_Event;
	};

}
