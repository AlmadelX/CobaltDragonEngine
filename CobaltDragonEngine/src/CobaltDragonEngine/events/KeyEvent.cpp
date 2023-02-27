#include "cdepch.h"
#include "KeyEvent.h"

namespace CDE {

	std::string KeyEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << m_Key;

		return out.str();
	}

	std::string KeyPressEvent::ToString() const
	{
		std::ostringstream out;
		out << GetName() << ": " << m_Key;
		if (m_Repeat)
			out << ", repeat";

		return out.str();
	}

}
