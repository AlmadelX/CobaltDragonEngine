#pragma once

#include <iostream>
#include <string>

#include "CobaltDragonEngine/Core.h"

#define BIND_EVENT_FUNCTION(function) std::bind(&function, this, std::placeholders::_1)

namespace CDE {

	// Right now blocking event system is implemented
	// TODO: implement event buffer
	class Event
	{
		friend class EventDispatcher;

	public:
		virtual std::string GetName() const = 0;
		inline virtual std::string ToString() const { return GetName(); }
		inline bool IsHandled() const { return m_Handled; }

	private:
		bool m_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& out, const Event& event) { return out << event.ToString(); }

}
