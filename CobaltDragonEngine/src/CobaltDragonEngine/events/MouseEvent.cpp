#include "cdepch.h"
#include "MouseEvent.h"

namespace CDE {

	std::string MouseMoveEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << std::fixed << std::setprecision(LOG_FLOAT_PRECISION) << m_X << ", " << m_Y;

		return out.str();
	}

	std::string MouseScrollEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << std::fixed << std::setprecision(LOG_FLOAT_PRECISION) << m_XOffset << ", " << m_YOffset;

		return out.str();
	}

	std::string MouseButtonEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << m_Button;

		return out.str();
	}

}
