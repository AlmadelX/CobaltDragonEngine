#pragma once

#if defined(CDE_PLATFORM_WINDOWS)
	#if defined(CDE_DEBUG)
		#define CDE_CORE_ASSERT(x, ...) { if(!(x)) { EN_CORE_ERROR("Assertion failed: {}", __VA_ARGS__); __debugbreak(); } }
		#define CDE_ASSERT(x, ...) { if(!(x)) { EN_ERROR("Assertion failed: {}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define CDE_CORE_ASSERT(x, ...)
		#define CDE_ASSERT(x, ...)
	#endif
#else
	#error CobaltDragonEngine supports only Windows for now
#endif
