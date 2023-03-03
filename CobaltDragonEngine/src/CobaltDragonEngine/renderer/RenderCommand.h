#pragma once

#include "RendererAPI.h"

namespace CDE {

	class RenderCommand
	{
	public:
		inline static void SetClearColor(glm::vec4 color) { s_RendererAPI->SetClearColor(color); }
		inline static void Clear() { s_RendererAPI->Clear(); }

	private:
		static RendererAPI* s_RendererAPI;
	};

}
