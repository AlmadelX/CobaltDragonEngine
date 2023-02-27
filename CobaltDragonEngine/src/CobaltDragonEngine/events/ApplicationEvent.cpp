#include "cdepch.h"
#include "ApplicationEvent.h"

namespace CDE {

	std::string AppTickEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << std::fixed << std::setprecision(LOG_FLOAT_PRECISION) << m_Delta;

		return out.str();
	}

}
