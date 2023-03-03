#include "cdepch.h"
#include "RendererAPI.h"

#if defined(CDE_PLATFORM_WINDOWS)
#include "platform/OpenGL/OpenGLAPI.h"
#endif

namespace CDE {

	RendererAPI* RendererAPI::Init()
	{
		switch (s_API)
		{
#if defined(CDE_PLATFORM_WINDOWS)
		case API::OpenGL:
		{
			return new OpenGLAPI;
		}
#endif
		default:
		{
			CDE_CORE_ERROR("Renderer API is not supported");
			return nullptr;
		}
		}
	}

	// General API switch
	RendererAPI::API RendererAPI::s_API = API::OpenGL;

}
