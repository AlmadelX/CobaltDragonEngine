#pragma once

#include "CobaltDragonEngine/Input.h"

namespace CDE {

	class WindowsInput : public Input
	{
	public:
		WindowsInput();

	protected:
		bool IsKeyPressedImpl(int keyCode) const override;

		std::pair<float, float> GetMousePosImpl() const override;
		float GetMouseXImpl() const override;
		float GetMouseYImpl() const override;

		bool IsMouseButtonPressedImpl(int button) const override;
	};

}
