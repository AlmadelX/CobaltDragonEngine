#pragma once

#include "CobaltDragonEngine/Layer.h"

namespace CDE {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer() : Layer("ImGui") {}

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	};

}
