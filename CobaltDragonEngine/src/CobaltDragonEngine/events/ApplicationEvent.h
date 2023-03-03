#pragma once

#include "Event.h"

namespace CDE {

	class ApplicationEvent : public Event {};

	class AppTickEvent final : public ApplicationEvent
	{
	public:
		AppTickEvent(float delta) noexcept : m_Delta(delta) {}
		AppTickEvent(const AppTickEvent& other) = delete;

		AppTickEvent& operator=(const AppTickEvent& other) = delete;

		inline virtual std::string GetName() const override { return "AppTickEvent"; }
		virtual std::string ToString() const override;

		inline float GetDelta() const { return m_Delta; }

	private:
		const float m_Delta;
	};

	class AppUpdateEvent final : public ApplicationEvent
	{
	public:
		AppUpdateEvent() = default;
		AppUpdateEvent(const AppUpdateEvent& other) = delete;

		AppUpdateEvent& operator=(const AppUpdateEvent& other) = delete;

		inline virtual std::string GetName() const override { return "AppUpdateEvent"; }
	};

	class AppRenderEvent final : public ApplicationEvent
	{
	public:
		AppRenderEvent() = default;
		AppRenderEvent(const AppRenderEvent& other) = delete;

		AppRenderEvent& operator=(const AppRenderEvent& other) = delete;

		inline virtual std::string GetName() const override { return "AppRenderEvent"; }
	};

}
