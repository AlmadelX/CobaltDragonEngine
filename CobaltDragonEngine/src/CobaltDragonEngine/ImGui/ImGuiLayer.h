#pragma once

#include "CobaltDragonEngine/Layer.h"

namespace CDE {

	class ImGuiLayer final : public Layer
	{
	public:
		ImGuiLayer() noexcept : Layer("ImGui") {}
		ImGuiLayer(const ImGuiLayer& other) = delete;

		ImGuiLayer& operator=(const ImGuiLayer& other) = delete;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	};

}
