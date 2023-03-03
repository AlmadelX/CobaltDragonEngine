#pragma once

#include <glm/vec4.hpp>

namespace CDE {

	class RendererAPI
	{
	public:
		enum class API
		{
			None, OpenGL
		};

		static RendererAPI* Init();

		inline static API GetAPI() { return s_API; }

		virtual ~RendererAPI() = default;

		virtual void SetClearColor(glm::vec4 color) const = 0;
		virtual void Clear() const = 0;

	private:
		static API s_API;
	};

}
