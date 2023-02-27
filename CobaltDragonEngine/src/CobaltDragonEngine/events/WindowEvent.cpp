#include "cdepch.h"
#include "WindowEvent.h"

namespace CDE {

	std::string WindowMoveEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << m_X << ", " << m_Y;

		return out.str();
	}

	std::string WindowResizeEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << m_Width << ", " << m_Height;

		return out.str();
	}

}
