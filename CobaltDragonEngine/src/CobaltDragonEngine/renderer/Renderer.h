#pragma once

#include "RenderCommand.h"

namespace CDE {

	class Renderer
	{
	public:
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
