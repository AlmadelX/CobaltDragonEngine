#pragma once

#include "Event.h"

namespace CDE {

	class ApplicationEvent : public Event
	{
	public:
		EVENT_CATEGORIES(EventCategoryApplication)
	};

	class AppTickEvent : public ApplicationEvent
	{
	public:
		EVENT_TYPE(AppTick)

		AppTickEvent(float delta) : m_Delta(delta) {}

		virtual std::string ToString() const override;

		inline float GetDelta() const { return m_Delta; }

	private:
		const float m_Delta;
	};

	class AppUpdateEvent : public ApplicationEvent
	{
	public:
		EVENT_TYPE(AppUpdate)
	};

	class AppRenderEvent : public ApplicationEvent
	{
	public:
		EVENT_TYPE(AppRender)
	};

}
