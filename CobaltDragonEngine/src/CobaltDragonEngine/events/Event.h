#pragma once

#include <iostream>
#include <string>

#include "CobaltDragonEngine/Core.h"

#define EVENT_TYPE(type) inline static constexpr EventType Type()			  { return EventType::##type; }\
						 inline virtual EventType GetType() const override	  { return Type(); }\
						 inline virtual std::string GetName() const override  { return #type "Event"; }

#define EVENT_CATEGORIES(categories) inline static constexpr int Categories()	   { return (categories); }\
								 inline virtual int GetCategories() const override { return Categories(); }

#define EVENT_HANDLER(handler) std::bind(&handler, this, std::placeholders::_1)

namespace CDE {

	enum class EventType
	{
		None,
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowFocus, WindowLostFocus, WindowMove, WindowResize,
		KeyPress, KeyRelease, KeyType,
		MouseMove, MouseScroll, MouseButtonPress, MouseButtonRelease
	};

	enum EventCategory
	{
		EventCategoryNone		 = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryWindow		 = BIT(1),
		EventCategoryInput		 = BIT(2),
		EventCategoryKeyboard	 = BIT(3),
		EventCategoryMouse		 = BIT(4),
		EventCategoryMouseButton = BIT(5)
	};

	// Blocking events
	// TODO: event buffer
	class Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetType() const = 0;
		virtual int GetCategories() const = 0;
		virtual std::string GetName() const = 0;

		inline virtual std::string ToString() const { return GetName(); }

		inline bool InCategory(EventCategory category) const { return GetCategories() & category; }
		inline bool IsHandled() const { return m_Handled; }

	private:
		bool m_Handled = false;
	};

	inline std::ostream& operator<<(std::ostream& out, const Event& event) { return out << event.ToString(); }

}
