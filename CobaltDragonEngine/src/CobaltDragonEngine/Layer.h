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
		Layer(const std::string& name) : m_Name{ name } {}

		inline const std::string& GetName() const { return m_Name; }

	protected:
		std::string m_Name;
#endif
	};

}
