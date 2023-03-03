#pragma once

#include "CobaltDragonEngine/renderer/RendererAPI.h"

namespace CDE {

	class OpenGLAPI : public RendererAPI
	{
		virtual void SetClearColor(glm::vec4 color) const override;
		virtual void Clear() const override;
	};

}
