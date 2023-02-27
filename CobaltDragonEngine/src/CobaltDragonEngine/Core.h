#pragma once

#if defined(CDE_DEBUG) || defined(CDE_RELEASE)
	#define CDE_ENABLE_LOGGING
#endif

#if defined(CDE_DEBUG)
	#define CDE_ENABLE_ASSERT
#endif

#if defined(CDE_ENABLE_ASSERT)
	#if defined(CDE_PLATFORM_WINDOWS)
		#define CDE_CORE_ASSERT(x, ...) { if(!(x)) { CDE_CORE_ERROR("Assertion failed: {}", __VA_ARGS__); __debugbreak(); } }
		#define CDE_ASSERT(x, ...) { if(!(x)) { CDE_ERROR("Assertion failed: {}", __VA_ARGS__); __debugbreak(); } }
	#else
		#error Cobalt Dragon Engine supports only Windows for now
	#endif
#else
	#define CDE_CORE_ASSERT(x, ...)
	#define CDE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
