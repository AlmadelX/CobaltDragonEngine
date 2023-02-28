#pragma once

#include <utility>

namespace CDE {

	class Input
	{
	public:
		static bool IsKeyPressed(int key)			 { return s_Instance->IsKeyPressedImpl(key); }

		static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		static float GetMouseX()					 { return s_Instance->GetMouseXImpl(); }
		static float GetMouseY()					 { return s_Instance->GetMouseYImpl(); }

		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }

	protected:
		inline static bool IsInstanceSet() { return s_Instance; }

		virtual bool IsKeyPressedImpl(int key) const = 0;

		virtual std::pair<float, float> GetMousePosImpl() const = 0;
		virtual float GetMouseXImpl() const = 0;
		virtual float GetMouseYImpl() const = 0;

		virtual bool IsMouseButtonPressedImpl(int button) const = 0;

	private:
		static Input* s_Instance;
	};

}
