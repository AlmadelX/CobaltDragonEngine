#pragma once

#include <spdlog/spdlog.h>

#if defined(CDE_DEBUG) || defined(CDE_RELEASE)
	#define CDE_CORE_TRACE(...) CDE::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define CDE_CORE_INFO(...) CDE::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define CDE_CORE_WARN(...) CDE::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define CDE_CORE_ERROR(...) CDE::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define CDE_CORE_CRITICAL(...) CDE::Log::GetCoreLogger()->critical(__VA_ARGS__)

	#define CDE_TRACE(...) CDE::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define CDE_INFO(...) CDE::Log::GetClientLogger()->info(__VA_ARGS__)
	#define CDE_WARN(...) CDE::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define CDE_ERROR(...) CDE::Log::GetClientLogger()->error(__VA_ARGS__)
	#define CDE_CRITICAL(...) CDE::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
	#define CDE_CORE_TRACE(...)
	#define CDE_CORE_INFO(...)
	#define CDE_CORE_WARN(...)
	#define CDE_CORE_ERROR(...)
	#define CDE_CORE_CRITICAL(...)

	#define CDE_TRACE(...)
	#define CDE_INFO(...)
	#define CDE_WARN(...)
	#define CDE_ERROR(...)
	#define CDE_CRITICAL(...)
#endif

namespace CDE {

	class Log
	{
		using Logger = std::shared_ptr<spdlog::logger>;

	public:
		static void Init();

		inline static Logger& GetCoreLogger() { return s_CoreLogger; }
		inline static Logger& GetClientLogger() { return s_ClientLogger; }

	private:
		static Logger s_CoreLogger;
		static Logger s_ClientLogger;
	};

}
