#include "cdepch.h"
#include "OpenGLAPI.h"

#include <glad/glad.h>

namespace CDE {

	void OpenGLAPI::SetClearColor(glm::vec4 color) const
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLAPI::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

}
