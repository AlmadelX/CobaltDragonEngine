#pragma once

#include <string>

#include "events/Event.h"

namespace CDE {

	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnEvent(Event& event) {}

#if defined(CDE_DEBUG)
		inline const std::string& GetName() const { return m_Name; }

	protected:
		Layer(const std::string& name) : m_Name{ name } {}

		std::string m_Name;
#else
	protected:
		Layer() = default;
#endif
	};

}
